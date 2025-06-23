#include <Wire.h>                    // Bibliothèque pour la communication I2C
#include <LiquidCrystal_I2C.h>       // Bibliothèque pour gérer l'écran LCD I2C

const int MPU = 0x68;                // Adresse I2C du capteur MPU6050 (valeur par défaut)

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialisation de l'écran LCD I2C (adresse 0x27, 16 colonnes, 2 lignes)

// Variables pour stocker les données d'accélération
float AccX, AccY, AccZ;
// Variables pour stocker les données de gyroscope
float GyroX, GyroY, GyroZ;

// Angles calculés à partir de l'accéléromètre
float accAngleX, accAngleY;
// Angles calculés à partir du gyroscope (intégrés)
float gyroAngleX, gyroAngleY, gyroAngleZ;

// Angles fusionnés (roll, pitch, yaw)
float roll, pitch, yaw;

// Erreurs calculées lors de la calibration (offsets à enlever)
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;

// Variables pour gérer le temps écoulé entre deux mesures
float elapsedTime, currentTime, previousTime;

// Compteur utilisé pour la calibration
int c = 0;

void setup() {
  Serial.begin(19200);         // Initialisation du port série à 19200 bauds pour debug
  Wire.begin();                // Démarrage de la communication I2C

  // Réveil du MPU6050 qui est en veille par défaut
  Wire.beginTransmission(MPU); // Démarrer la transmission vers MPU
  Wire.write(0x6B);            // Registre PWR_MGMT_1 (gestion alimentation)
  Wire.write(0x00);            // Mettre à 0 pour sortir du mode veille
  Wire.endTransmission(true);  // Fin de la transmission

  // Initialisation de l'écran LCD
  lcd.begin(16, 2);            // Définir taille LCD (16x2)
  lcd.backlight();             // Activer rétroéclairage
  lcd.setCursor(0, 0);         // Positionner curseur au début ligne 0
  lcd.print("Initialisation..."); // Message de démarrage
  delay(1000);                 // Pause d'1 seconde
  lcd.clear();                 // Effacer écran

  // Calibration automatique du capteur (calcul des erreurs à soustraire)
  calculate_IMU_error();
  delay(20);                   // Petite pause
}

void loop() {
  // === Lecture des valeurs brutes de l'accéléromètre ===
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);                    // Adresse du registre de début des données Accel
  Wire.endTransmission(false);        // Garder la communication ouverte
  Wire.requestFrom(MPU, 6, true);     // Lire 6 octets (2 par axe X,Y,Z)

  // Conversion des données brutes en valeurs en g (gravité)
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // Accélération X
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Accélération Y
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Accélération Z

  // Calcul des angles d'inclinaison (roll, pitch) avec accéléromètre
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorX;
  accAngleY = (atan(-AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorY;

  // === Lecture des valeurs brutes du gyroscope ===
  previousTime = currentTime;           // Sauvegarde du temps précédent
  currentTime = millis();                // Temps actuel en ms
  elapsedTime = (currentTime - previousTime) / 1000;  // Temps écoulé en secondes

  Wire.beginTransmission(MPU);
  Wire.write(0x43);                    // Adresse du registre de début des données Gyro
  Wire.endTransmission(false);        // Garder la communication ouverte
  Wire.requestFrom(MPU, 6, true);     // Lire 6 octets (2 par axe X,Y,Z)

  // Conversion des données brutes en degrés/seconde
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;

  // Soustraction des erreurs calculées lors de la calibration
  GyroX = GyroX - GyroErrorX;
  GyroY = GyroY - GyroErrorY;
  GyroZ = GyroZ - GyroErrorZ;

  // Intégration des vitesses angulaires pour obtenir les angles
  gyroAngleX += GyroX * elapsedTime;
  gyroAngleY += GyroY * elapsedTime;
  yaw += GyroZ * elapsedTime;

  // Application d'un filtre complémentaire pour combiner accéléromètre et gyroscope
  // On donne plus de poids au gyroscope (0.96) car plus précis sur court terme
  // L'accéléromètre corrige la dérive du gyroscope sur le long terme (0.04)
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;

  // === Détection simple de la direction du mouvement en fonction des angles ===
  String direction = "haut"; // Valeur par défaut

  if (roll < -40 ) direction = "Avant";
  else if (roll < 80 && roll > 60) direction = "Arriere";
  else if (pitch > 15) direction = "Droite";
  else if (pitch < -15) direction = "Gauche";
  else if (pitch > 30) direction = "Haut";
  else if (pitch > 120 && roll > 100) direction = "Bas";

  // === Affichage de la direction détectée sur l'écran LCD ===
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Direction:");
  lcd.setCursor(0, 1);
  lcd.print(direction);

  // Affichage des angles pour debug sur moniteur série
  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" | Pitch: "); Serial.print(pitch);
  Serial.print(" | Yaw: "); Serial.println(yaw);

  delay(300); // Pause avant prochaine lecture
}

// === Fonction pour calibrer automatiquement le capteur au démarrage ===
void calculate_IMU_error() {
  // Calibration accéléromètre : moyenne des angles calculés sur plusieurs mesures
  while (c < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);

    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;

    // Calcul des angles roll et pitch à partir de l'accéléromètre
    AccErrorX += atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI;
    AccErrorY += atan(-AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI;

    c++;
  }
  // Moyenne des erreurs calculées
  AccErrorX /= 200;
  AccErrorY /= 200;
  c = 0; // Réinitialisation compteur

  // Calibration gyroscope : moyenne des valeurs lues au repos
  while (c < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);

    GyroX = Wire.read() << 8 | Wire.read();
    GyroY = Wire.read() << 8 | Wire.read();
    GyroZ = Wire.read() << 8 | Wire.read();

    GyroErrorX += GyroX / 131.0;
    GyroErrorY += GyroY / 131.0;
    GyroErrorZ += GyroZ / 131.0;

    c++;
  }
  // Moyenne des erreurs gyroscopiques
  GyroErrorX /= 200;
  GyroErrorY /= 200;
  GyroErrorZ /= 200;

  // Affichage des résultats de calibration dans le moniteur série
  Serial.println("Calibration Terminee:");
  Serial.print("AccErrorX: "); Serial.println(AccErrorX);
  Serial.print("AccErrorY: "); Serial.println(AccErrorY);
  Serial.print("GyroErrorX: "); Serial.println(GyroErrorX);
  Serial.print("GyroErrorY: "); Serial.println(GyroErrorY);
  Serial.print("GyroErrorZ: "); Serial.println(GyroErrorZ);
}

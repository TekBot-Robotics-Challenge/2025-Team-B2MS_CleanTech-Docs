#include <Wire.h>               // Bibliothèque pour communication I2C
#include <LiquidCrystal_I2C.h>  // Bibliothèque pour écran LCD I2C
#include <MPU6050.h>            // Bibliothèque pour capteur MPU6050

// Initialisation écran LCD avec adresse I2C 0x27, 16 colonnes et 2 lignes
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Création instance MPU6050
MPU6050 mpu;

// Variables pour stocker l'accélération en g (gravité)
float ax, ay, az;

// Norme totale de l'accélération (valeur absolue)
float accel_norm;

// Seuil d'accélération (en g) pour détecter un mouvement significatif
const float threshold = 0.2;

void setup() {
  Serial.begin(9600);  // Initialisation communication série à 9600 bauds (pour debug éventuel)
  Wire.begin();        // Initialisation bus I2C

  lcd.init();          // Initialisation écran LCD
  lcd.backlight();     // Allumer rétroéclairage LCD

  // Initialisation MPU6050
  mpu.initialize();

  // Vérification de la connexion avec MPU6050
  if (!mpu.testConnection()) {
    lcd.print("MPU6050 error"); // Affiche erreur si capteur non détecté
    while (1);                  // Bloque le programme ici (boucle infinie)
  }

  lcd.clear();
  lcd.print("MPU6050 OK"); // Confirmation que capteur est prêt
  delay(1000);
  lcd.clear();
}

void loop() {
  // Variables pour stocker les valeurs brutes (raw) lues depuis MPU6050
  int16_t rawAx, rawAy, rawAz;

  // Lecture des valeurs d'accélération brute sur 3 axes
  mpu.getAcceleration(&rawAx, &rawAy, &rawAz);

  // Conversion des valeurs brutes en unités g (gravité)
  // Selon datasheet, la sensibilité est 16384 LSB/g en mode ±2g
  ax = rawAx / 16384.0;
  ay = rawAy / 16384.0;
  az = rawAz / 16384.0;

  // Calcul de la norme de l'accélération totale vectorielle
  // sqrt(x² + y² + z²) -> donne l'intensité totale ressentie
  accel_norm = sqrt(ax * ax + ay * ay + az * az);

  // Détection de la direction dominante en fonction du seuil
  String direction = "";    // Texte à afficher (direction détectée)
  if (ax > threshold) { 
    direction = "Gauche";   // Si acceleration sur axe X positive > seuil
  }
  else if (ax < -threshold) {
    direction = "Droite";   // Si acceleration sur axe X négative < -seuil
  }
  else if (ay > threshold) {
     direction = "Arriere";  // Si acceleration sur axe Y positive > seuil
  }
  else if (ay < -threshold) {
     direction = "Avant";    // Si acceleration sur axe Y négative < -seuil
  }
  else if (az > threshold) {
    direction = "Haut";      // Si acceleration sur axe Z positive > seuil
  }
  else if (az < -threshold) {
    direction = "Bas";       // Si acceleration sur axe Z négative < -seuil
  }
  else {
    direction = "Stable";    // Si aucune acceleration significative détectée
  }
 
  // Affichage sur l'écran LCD
  lcd.clear();              // Efface l'écran à chaque boucle
  lcd.setCursor(0, 0);      // Position curseur ligne 0, colonne 0
  lcd.print("Dir: ");       // Affiche label "Direction"
  lcd.print(direction);     // Affiche la direction détectée

  lcd.setCursor(0, 1);      // Position curseur ligne 1, colonne 0
  lcd.print("Accel: ");     // Affiche label "Accélération"
  lcd.print(accel_norm, 2); // Affiche la norme de l'accélération avec 2 décimales
  lcd.print(" g");          // Affiche unité g (gravité)

  delay(300);               // Pause de 300 ms avant prochaine lecture
}

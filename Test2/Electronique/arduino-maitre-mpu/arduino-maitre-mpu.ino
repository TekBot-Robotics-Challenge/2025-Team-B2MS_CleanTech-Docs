#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

float ax, ay, az;
const float threshold = 0.2;
String direction = "";

void setup() {
  Serial.begin(9600);
  Wire.begin();      // Maître
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("Erreur MPU6050");
    while (1);
  }

  Serial.println("MPU6050 OK");
}

void loop() {
  int16_t rawAx, rawAy, rawAz;
  mpu.getAcceleration(&rawAx, &rawAy, &rawAz);

  ax = rawAx / 16384.0;
  ay = rawAy / 16384.0;
  az = rawAz / 16384.0;

  // Détection de direction
  if (ax > threshold) direction = "Gauche";
  else if (ax < -threshold) direction = "Droite";
  else if (ay > threshold) direction = "Arriere";
  else if (ay < -threshold) direction = "Avant";
  else if (az > threshold) direction = "Haut";
  else if (az < -threshold) direction = "Bas";
  else direction = "Stable";

  // Envoi vers esclave
  Wire.beginTransmission(8);         // adresse esclave
  Wire.write(direction.c_str());     // envoyer la direction comme texte
  Wire.endTransmission();

  Serial.print("Direction envoyée : ");
  Serial.println(direction);

  delay(300);
}

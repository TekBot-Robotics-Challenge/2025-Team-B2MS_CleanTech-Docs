#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD I2C

String receivedDirection = "";

void setup() {
  Wire.begin(8);  // Adresse de l'esclave
  Wire.onReceive(receiveData);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pret a recevoir");
}

void loop() {
  // Affiche la dernière direction reçue
  lcd.setCursor(0, 0);
  lcd.print("Dir:            "); // Nettoyer la ligne
  lcd.setCursor(5, 0);
  lcd.print(receivedDirection);
  
  delay(200);
}

void receiveData(int bytes) {
  receivedDirection = ""; // réinitialiser

  while (Wire.available()) {
    char c = Wire.read();
    receivedDirection += c;
  }

  Serial.print("Recu : ");
  Serial.println(receivedDirection);
}
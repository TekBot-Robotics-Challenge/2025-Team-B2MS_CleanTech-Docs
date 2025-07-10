
    const int ledCount = 8;    // Number of LEDs on the module
    const int colourCount = 3; // Number of colors (RGB)
    int ledPins[] = { 6, 7, 8, 9, 10, 11, 12, 13 }; // Assign pin numbers to each LED
    int colourPins[] = { 3, 4, 5 }; // Assign pin numbers to RGB color channels

    void setup() {
      for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        pinMode(ledPins[thisLed], OUTPUT);
        digitalWrite(ledPins[thisLed], HIGH);
      }
      for (int thisColour = 0; thisColour < colourCount; thisColour++) {
        pinMode(colourPins[thisColour], OUTPUT);
        digitalWrite(colourPins[thisColour], HIGH);
      }
    }

    void loop() {
      for (int thisColour = 0; thisColour < colourCount; thisColour++) {
        digitalWrite(colourPins[thisColour], LOW);

        for (int thisLed = 0; thisLed < ledCount; thisLed++) {
          digitalWrite(ledPins[thisLed], LOW);
          delay(100);
          digitalWrite(ledPins[thisLed], HIGH);
        }
        
        digitalWrite(colourPins[thisColour], HIGH);
      }
    }
                
#include <ColorPAL.h>

ColorPAL sensor;

void setup()
{
  sensor.attachPAL(12);                 // Attaches sensor to digital pin 12
  Serial.begin(9600);
}

void loop()
{
  int red = sensor.redPAL();            // Reads sensors and returns red value
  int green = sensor.greenPAL();        // Reads sensors and returns green value
  int blue = sensor.bluePAL();          // Reads sensors and returns blue value
  Serial.print(red); Serial.print(" ");
  Serial.print(green); Serial.print(" ");
  Serial.println(blue);
}

#include <ColorPAL.h>

#define colorSensorPin 12
ColorPAL colorSensor;

#define RED_PIN 3  // Pin for red color
#define GREEN_PIN 5  // Pin for green color
#define BLUE_PIN 6 // Pin for blue color

#define LED0 2 //led

// Capteur ultrason
#define TRIG_PIN 18
#define ECHO_PIN 19

// Contrôle moteur
#define enA 11
#define in1 10
#define in2 9

long distance = 0;
char color_detected = 'U';
unsigned long   previous_time;
unsigned long   current_time;
unsigned long   delta_T = 2.5; // in seconds


void setup()
{
  // Moteur
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enA, 38); // vitesse initiale

  // Ultrason
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

   // Capteur de couleur
  colorSensor.attachPAL(colorSensorPin);                 // Attaches color sensor           

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  pinMode(LED0, OUTPUT);

  Serial.begin(9600);
  distance = getDistance();
}



void loop() { 
  if (distance < 25) {
    for (int i = 0; i <= 20; i++)
    color_detected = readColor();
    Serial.println(color_detected);
    digitalWrite(LED0, LOW);
    switch(color_detected){
      case 'R':
        setColor(250, 0, 0); //red
        break;
      case 'G':
        setColor(0, 250, 0); //green
        break;
      case 'B':
        setColor(0, 0, 250); //blue
        break;
      case 'Y':
        setColor(200, 250, 0); //yellow
        break;
      default:
        setColor(60, 100, 100);
        break;
   }
    delay(2000);
    while (distance < 25) {
      analogWrite(enA, 100);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      delay(50);
      distance = getDistance(); // Mettre à jour la distance
    }
  } else {
   previous_time= millis();
   current_time= previous_time;
   while((current_time - previous_time)/1000 < delta_T){
      analogWrite(enA, 100);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      current_time= millis();
   }
  analogWrite(enA, 0);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  while(distance >= 25) {distance = getDistance();
  }
}}


// Function to set color for all LEDs
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Fonction pour lire la couleur via TCS3200
char readColor() {
  int red = colorSensor.redPAL();     
  int green = colorSensor.greenPAL(); 
  int blue = colorSensor.bluePAL();   
  
  if(50 < red && red < 255 && 0 < green && green < 17 && 0 < blue && blue < 17) return 'R';  // Rouge
  else if (0 < red && red < 17 && 16 < green && green < 255 && 0 < blue && blue < 30) return 'G';  // Vert
  else if (0 < red && red < 17 && 16 < green && green < 255 && 30 < blue && blue < 255) return 'B';  // Bleu

  return 'Y'; // Yellow
}

// Fonction pour lire la distance avec le capteur ultrason
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2.0) * 0.0344;
  return distance;
}

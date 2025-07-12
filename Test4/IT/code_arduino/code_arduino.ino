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

int red = 0, green = 0, blue = 0;

long distance = 0;
char color_detected = 'U';

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
  colorSensor.attachPAL(colorSensorPin);        // Attaches color sensor           

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  pinMode(LED0, OUTPUT);
  digitalWrite(LED0, HIGH);


  Serial.begin(9600);
}

void loop(){
  distance = getDistance();
  //Serial.println(distance);

  if(distance < 65){
    if(9 < distance && distance < 13){
      analogWrite(enA, 0);
      digitalWrite(in2, LOW);
      digitalWrite(in1, LOW);

      //detection de couleur
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
      analogWrite(enA, 100);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      delay(500);
    }
    analogWrite(enA, 100);
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    delay(20);
  }
  else{
    analogWrite(enA, 0);
    digitalWrite(in2, LOW);
    digitalWrite(in1, LOW);
  }
}


// Function to set color for all LEDs
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Fonction pour lire la couleur via TCS3200
char readColor() {
  red = 0;
  green = 0;
  blue = 0;
  // 10 echantillons de chaque valeur RGB
  for(int i = 0; i < 10; i++){
    red += colorSensor.redPAL();     
    green += colorSensor.greenPAL(); 
    blue += colorSensor.bluePAL();   
  }
  red = red/10;
  green = green/10;
  blue = blue/10;

  if(40 < red && red < 255 && 0 < green && green < 17 && 0 < blue && blue < 17) return 'R';  // Rouge
  else if (0 < red && red < 17 && 10 < green && green < 255 && 0 < blue && blue < 30) return 'G';  // Vert
  else if (0 < red && red < 17 && 0 < green && green < 255 && 30 < blue && blue < 255) return 'B';  // Bleu

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

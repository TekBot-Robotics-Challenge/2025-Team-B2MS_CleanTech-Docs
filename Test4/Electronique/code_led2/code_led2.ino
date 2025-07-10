#define RED_PIN 3  // Pin for red color
#define GREEN_PIN 4  // Pin for green color
#define BLUE_PIN 5 // Pin for blue color

#define D0 6

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  pinMode(D0, OUTPUT);
}


void loop() { 
  setColor(255, 0, 0); //red
  delay(2000); 

  setColor(0, 255, 0); //green
  delay(2000); 

  setColor(0, 0, 255); //blue
  delay(2000); 

  setColor(255, 155, 0); //yellow
  delay(2000); 
}


// Function to set color for all LEDs
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
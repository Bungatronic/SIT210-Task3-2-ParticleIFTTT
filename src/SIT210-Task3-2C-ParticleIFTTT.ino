/*
 * Project SIT210-Task3-2C-ParticleIFTTT
 * Description:
 * Author:
 * Date:
 */
//#define LIGHT_PIN   A4

//float light=10;
#define MOTION_PIN A4

bool motion;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(MOTION_PIN, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  //light=analogRead(LIGHT_PIN);
  //light=11;
  //Serial.printlnf("Light: %f", light);
  motion=digitalRead(MOTION_PIN);

  if(motion==true){
    Serial.println("Motion Detected");
  } 
  else{
    Serial.println("No Motion");
  }

  delay(2000);
}
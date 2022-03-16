#define MOTION_PIN  D0  // PIR input pin
#define LED_PIN     D2  // LED output pin

bool motion=0;          // Current motion status
bool prev_motion=0;     // Previous motion status

void setup() {
  pinMode(MOTION_PIN, INPUT); // Initialise motion sensor pin
  pinMode(LED_PIN, OUTPUT);   // Initialise LED pin
  Serial.begin(9600);
}

void loop() {
  bool prev_motion=motion;        // Store previous motion status
  motion=digitalRead(MOTION_PIN); // Read PIR sensor

  // If motion status has changed, update LED to reflect and publish status change to IFTTT
  if(prev_motion!=motion) {
    if(motion==true){
      digitalWrite(LED_PIN, HIGH);
      Particle.publish("Motion_Status", "Motion Detected");
    }
    else {
      digitalWrite(LED_PIN, LOW);
      Particle.publish("Motion_Status", "No Motion");
    }
  }

  delay(1000);
}
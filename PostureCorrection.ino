// Posture Correction Device using Ultrasonic Sensor + Buzzer
// Written in Arduino C

// Pin definitions
const int trigPin = 9;     // Ultrasonic sensor TRIG pin
const int echoPin = 10;    // Ultrasonic sensor ECHO pin
const int buzzerPin = 8;   // Buzzer pin

// Variables
long duration;
int distance;
const int safeDistance = 40; // in cm, adjust according to your setup

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Open serial monitor
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check posture
  if (distance < safeDistance) {
    // Too close → bad posture
    digitalWrite(buzzerPin, HIGH);  // Turn buzzer ON
  } else {
    // Good posture
    digitalWrite(buzzerPin, LOW);   // Turn buzzer OFF
  }

  delay(500); // small delay
}

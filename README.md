# Posture Correction Device

An Arduino-based **Posture Correction Device** that uses an **HC-SR04 Ultrasonic Sensor** to measure the distance between the user and the sensor.  
If the user leans too close (bad posture), the device triggers a **buzzer alert**.  

---

Features
- Detects poor posture using distance measurement.
- Provides instant buzzer feedback to correct posture.
- Simple USB connection to laptop for power & serial monitoring.
- Expandable (can be adapted with vibration motor, Bluetooth, or data logging).

---

Components Required
- Arduino UNO (or compatible board)
- HC-SR04 Ultrasonic Sensor
- Buzzer (or vibration motor)
- Jumper wires
- Breadboard (optional)
- USB cable (Arduino ↔ Laptop)

---

Circuit Connections
**Ultrasonic Sensor (HC-SR04):**
- VCC → 5V  
- GND → GND  
- TRIG → Pin 9  
- ECHO → Pin 10  

**Buzzer:**
- Positive → Pin 8  
- Negative → GND  

---

Arduino Code
The Arduino sketch measures distance using the ultrasonic sensor:  

- If **distance < 40 cm** → buzzer ON (bad posture).  
- Else → buzzer OFF (good posture).  
- Distance readings are printed to the Serial Monitor.  

```c
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

long duration;
int distance;
const int safeDistance = 40;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < safeDistance) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}

---

Usage

1. Connect the Arduino to your laptop using a USB cable.

2. Upload the provided code using the Arduino IDE.

3. Open Serial Monitor (Ctrl+Shift+M) to see distance readings.

4.

Sit in front of the sensor - if you lean too close, the buzzer will beep!



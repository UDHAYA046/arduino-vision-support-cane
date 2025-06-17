# 🦯 Arduino Enhanced Vision Support Cane (Smart Walking Stick)

An embedded C-based assistive device for **visually impaired individuals**, integrating ultrasonic and moisture sensors, speaker alerts, and an SOS panic button. This system provides **real-time feedback** about obstacles, water presence, and emergencies—enhancing mobility and safety.

---

## 📘 Table of Contents
- [🧠 Abstract](#abstract)
- [🎯 Project Goal](#project-goal)
- [⚙️ Hardware Requirements](#hardware-requirements)
- [💻 Software Requirements](#software-requirements)
- [📈 System Flow](#system-flow)
- [📦 Modules Overview](#modules)
- [🔌 Circuit Simulation](#circuit-simulation)
- [💡 Implementation Details](#implementation)
- [🧪 Sample Arduino Code](#sample-arduino-code)
- [💰 Project Budget](#project-budget)
- [🏁 Conclusion](#conclusion)
- [👩‍💻 Authors](#authors)

---

## 🧠 Abstract

This project introduces a **smart walking stick** aimed at improving the mobility of visually impaired individuals. It uses an **ultrasonic sensor** to detect obstacles and a **moisture sensor** to identify wet surfaces. A **buzzer and speaker system** provides real-time alerts. Additionally, a **panic button with SOS functionality** is included for emergency support.

---

## 🎯 Project Goal

To develop a **low-cost**, **portable**, and **reliable smart cane** that:
- Detects obstacles and water hazards
- Alerts the user through sound and vibration
- Provides emergency signaling through a panic button

---

## ⚙️ Hardware Requirements

| Component               | Quantity | Purpose                                    |
|------------------------|----------|--------------------------------------------|
| Arduino Uno            | 1        | Microcontroller board                      |
| Ultrasonic Sensor (HC-SR04) | 1  | Obstacle detection                         |
| Soil Moisture Sensor   | 1        | Detects water on ground                    |
| Buzzer                 | 1        | Alerts the user (audio feedback)           |
| Mini Speaker           | 1        | Audible feedback                           |
| LED                    | 1        | Visual indicator for alerts                |
| Panic Button (SOS)     | 1        | Emergency signaling                        |
| 9V Battery             | 1        | Powers the circuit                         |
| Jumper Wires + Breadboard | Many | Prototyping and connections                |
| Cane or Stick          | 1        | Mounting platform for the components       |

---

## 💻 Software Requirements

- **Arduino IDE** – for writing, uploading, and testing code
- **Embedded-C** – for implementing logic on Arduino Uno

---

## 📈 System Flow

1. **Obstacle Detection:** If an obstacle is detected within 50 cm, alert the user via buzzer.
2. **Moisture Detection:** If water is detected, emit a distinct tone to warn of slippery surfaces.
3. **Light Sensor (optional):** Detect ambient light level and alert if too low.
4. **Panic Button:** Sends SOS alert via sound or RF signal in case of emergency.

> ✅ See flowchart in the uploaded PDF: `BLIND WALKING STICK_2024-08-17_11-07-28.pdf`

---

## 📦 Modules

- **Obstacle Detection Module:** HC-SR04 + buzzer
- **Moisture Detection Module:** Analog moisture sensor
- **Speaker Module:** Voice alert on danger
- **SOS Module:** Panic button triggering emergency tone
- **Power Management:** 9V battery and switch control

---

## 🔌 Circuit Simulation

🔗 [Tinkercad Simulation](https://www.tinkercad.com/things/aj2Bhaut9Lh-c-simulation-1)

---

## 💡 Implementation

- Real-time sensing via analog and digital pins
- Distinct buzzer frequencies for different hazards
- SOS button triggers emergency alert even without sensor input

---

## 🧪 Sample Arduino Code

```c
#define trigPin 9
#define echoPin 8
#define buzzerPin 7
#define moisturePin A0
#define ledPin 13

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  int moistureValue = analogRead(moisturePin);

  if (moistureValue > 30) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else if (distance < 50) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);
  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}

💰 Project Budget
Item	Cost (INR)
Arduino Uno	₹2636
Ultrasonic Sensor	₹169
Moisture Sensor	₹120
Buzzer + 9V Battery	₹90
Panic Button (SOS switch)	₹299
Mini Speaker	₹90
Jumper Wires + Breadboard	₹250
USB Cable	₹200
Stick/Cane (Mount)	₹200–₹300

🟰 Total Estimated Cost: ~ ₹4150

🏁 Conclusion
The Arduino Enhanced Vision Support Cane project successfully demonstrates how low-cost electronics and embedded systems can be applied to solve real-world accessibility challenges. By integrating multiple modules, the system offers safety, portability, and enhanced independence for visually impaired users.

👩‍💻 Authors
S Udhaya Sankari – BL.EN.U4CSE23150

Institution: Amrita Vishwa Vidyapeetham, Bangalore

Semester: 3rd Semester | Submitted on: 20 August

📄 License
This project is licensed under the MIT License.

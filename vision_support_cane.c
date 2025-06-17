
#define trigPin 9        // Define the pin for the ultrasonic sensor trigger
#define echoPin 8        // Define the pin for the ultrasonic sensor echo
#define buzzerPin 7      // Define the pin for the buzzer
#define moisturePin A0   // Define the pin for the moisture sensor
#define ledPin 13        // Define the pin for the LED

void setup() {
  pinMode(trigPin, OUTPUT);   // Set trigPin as OUTPUT
  pinMode(echoPin, INPUT);    // Set echoPin as INPUT
  pinMode(buzzerPin, OUTPUT); // Set buzzerPin as OUTPUT
  pinMode(ledPin, OUTPUT);    // Set ledPin as OUTPUT
  Serial.begin(9600);         // Initialize serial communication at 9600 baud
}

void loop() {
  // Ultrasonic Sensor Logic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  int moistureValue = analogRead(moisturePin);
  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  bool moistureAlert = false;
  bool obstacleAlert = false;

  if (moistureValue > 30) {
    moistureAlert = true;
  }

  if (distance < 50) {
    obstacleAlert = true;
  }

  if (moistureAlert) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else if (obstacleAlert) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);
  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}

// Define sensor pins
const int flameSensorPin = A0;  // Analog pin for flame sensor
const int mq2SensorPin = A1;    // Analog pin for MQ2 sensor
const int buzzerPin = 8;        // Digital pin for buzzer

// Thresholds (tune based on your environment)
const int flameThreshold = 500; // lower = more flame
const int smokeThreshold = 300; // higher = more smoke

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int flameValue = analogRead(flameSensorPin);
  int smokeValue = analogRead(mq2SensorPin);

  Serial.print("Flame: ");
  Serial.print(flameValue);
  Serial.print(" | Smoke: ");
  Serial.println(smokeValue);

  // Check for fire or smoke
  if (flameValue < flameThreshold || smokeValue > smokeThreshold) {
    digitalWrite(buzzerPin, HIGH);  // Turn on buzzer
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn off buzzer
  }

  delay(500);
}
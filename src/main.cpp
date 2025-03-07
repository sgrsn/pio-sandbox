#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("Blinking");
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
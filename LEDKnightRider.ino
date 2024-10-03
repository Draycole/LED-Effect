int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};  // LED pins
int numLeds = 11; // Number of LEDs
int brightness = 0;
int fadeAmount = 5;
int delayTime = 30;  // Speed control

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set all pins as outputs
  }
}

void loop() {
  // First pattern: LED wave effect
  for (int i = 0; i < numLeds; i++) {
    analogWrite(ledPins[i], brightness);  // Gradually fade in the LEDs
    delay(delayTime);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;  // Reverse fade direction at limits
    }
  }

  // Second pattern: Bouncing LED effect
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }

  // Third pattern: Double bounce effect
  for (int i = 0; i < numLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLeds - 1 - i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLeds - 1 - i], LOW);
  }

  for (int i = numLeds / 2 - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLeds - 1 - i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLeds - 1 - i], LOW);
  }

  // Reset brightness for next loop
  brightness = 0;
}

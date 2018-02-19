#include <Arduino.h>

const int LED_PIN = 8; // LED 1
const int BUTTON_PIN = 2;
const int TILT_PIN = 3;

int buttonState = 0;
int tiltState = 0;

long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers

int previousButtonState = 0;

void setup () {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN , INPUT);     // declare sensor as input
  pinMode(TILT_PIN , INPUT);     // declare sensor as input
  // pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop () {

  buttonState = digitalRead(BUTTON_PIN);
  // Serial.println("buttonState");
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  if (previousButtonState != buttonState) {
    Serial.println("Button status changed");
    previousButtonState = buttonState;
  }

  tiltState = digitalRead(TILT_PIN);

  Serial.println(tiltState);

  delay(1000);

  // digitalWrite(LED_PIN, HIGH); //allumer L1
  // delay(1000); // attendre 1 seconde
  // digitalWrite(LED_PIN, LOW); // Eteindre L1
  // delay(2000); // attendre 2 seconde
}

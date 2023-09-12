#include <Arduino.h>

#define PIN_LED LED_BUILTIN
#define PIN_LAISER 16
#define PIN_SWITCH 17

void setup() {
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  ledcSetup(0, 20000, 10);
  ledcSetup(1, 20000, 10);
  ledcAttachPin(PIN_LED, 0);
  ledcAttachPin(PIN_LAISER, 1);
}

void loop() {
  if (digitalRead(PIN_SWITCH) == 0) {
    ledcWrite(0, 1022);
    ledcWrite(1, 1022);
  } else {
    ledcWrite(0, 100);
    ledcWrite(1, 100);
  }
  delay(10);
}
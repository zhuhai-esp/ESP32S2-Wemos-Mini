#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  ledcSetup(0, 5000, 12);
  ledcAttachPin(LED_BUILTIN, 0);
}

void loop() {
  for (int i = 0; i < 200; i++) {
    ledcWrite(0, abs(100 - i));
    delay(10);
  }
}
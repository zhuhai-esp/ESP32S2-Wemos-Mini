#include <Arduino.h>

void blinkTask(void *) {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
    static int round = 0;
    Serial.printf("Blink Task [%d]\n", round++);
  }
}

void printTask(void *) {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
    static int round = 0;
    Serial.printf("Print Task [%d]\n", round++);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  xTaskCreatePinnedToCore(blinkTask, "BlinkTask", 4096, NULL, 5, NULL, 0);
  xTaskCreatePinnedToCore(printTask, "PrintTask", 4096, NULL, 4, NULL, 0);
}

void loop() {}
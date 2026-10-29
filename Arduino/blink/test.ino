#include "blink.h"

const int LED_PIN = 2;
unsigned int tick = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(
        LED_PIN,
        led_should_be_on(tick) ? HIGH : LOW
    );

    tick++;
    delay(500);
}

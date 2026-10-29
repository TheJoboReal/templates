#include <Arduino.h>
#line 1 "/home/kasper/Documents/temp/ardu/test/test.ino"
#include "blink.h"

const int LED_PIN = 2;
unsigned int tick = 0;

#line 6 "/home/kasper/Documents/temp/ardu/test/test.ino"
void setup();
#line 10 "/home/kasper/Documents/temp/ardu/test/test.ino"
void loop();
#line 6 "/home/kasper/Documents/temp/ardu/test/test.ino"
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


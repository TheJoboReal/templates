#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Change to your board's LED pin
#define LED_PIN 2

void blinkTask(void *parameter) {
    pinMode(LED_PIN, OUTPUT);

    while (true) {
        digitalWrite(LED_PIN, HIGH);
        vTaskDelay(pdMS_TO_TICKS(500));

        digitalWrite(LED_PIN, LOW);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void serialTask(void *parameter) {
    while (true) {
        Serial.println("Hello from FreeRTOS!");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void setup() {
    Serial.begin(115200);

    xTaskCreate(
        blinkTask,    // Function
        "Blink",      // Name
        2048,         // Stack size in bytes on ESP32
        NULL,         // Parameters
        1,            // Priority
        NULL          // Task handle
    );

    xTaskCreate(
        serialTask,
        "Serial",
        2048,
        NULL,
        1,
        NULL
    );
}

void loop() {
    // Arduino's loop also runs in a FreeRTOS task.
    delay(1000);
}

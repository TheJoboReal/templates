#include "blink.h"

int led_should_be_on(unsigned int tick) {
    return tick % 2 == 0;
}

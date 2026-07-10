/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "scheduler.h"
#include "tusb.h"
#include <stdio.h>

static bool led_state = false;

void led_task() {
  gpio_put(PICO_DEFAULT_LED_PIN, led_state);
  led_state = !led_state;
}

void init_led(void) {
  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}

void hello_task() {
  printf("Hello\n");
}


// Array of tasks for the scheduler and their frequencies in milliseconds
//
// This can't be `const`, as the task values are modifies
// as the scheduler runs.
static Task TASKS[] = {
    CREATE_TASK(led_task, 200),
    CREATE_TASK(hello_task, 300),
};

int main() {
  stdio_init_all();
  tusb_init();
  init_led();
  sleep_ms(500);

  Scheduler scheduler;
  Task *tasks = (Task *)TASKS;
  uint task_count = sizeof(TASKS) / sizeof(TASKS[0]);
  scheduler_init(&scheduler, tasks, task_count);

  printf("\nTASKS:\n");
  for (int i = 0; i < task_count; i++) {
    printf("    Name: %s, Freq: %lld ms\n", tasks[i].name,
           tasks[i].frequency_us / 1000);
  }

  while (true) {
    tud_task();
    scheduler_poll(&scheduler);
  }
}

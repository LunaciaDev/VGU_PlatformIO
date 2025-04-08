#include <Arduino.h>
#include "software_timer.h"

static void TIMER_ISR(void *pvParameters) {
    while (1) {
        Timer_Tasks();
        vTaskDelay(10);
    }
}

void Init_Timer(void) {
    xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);
}

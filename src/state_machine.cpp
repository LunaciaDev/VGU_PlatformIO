#include <Arduino.h>
#include "software_timer.h"

#define LED_ON 0
#define LED_OFF 1
#define INIT 2

static int state = INIT;

void StateMachine_Init(void) {
    pinMode(GPIO_NUM_48, OUTPUT);
    Set_Timer(0, 10);
}

void StateMachine_Run(void) {
    if (Is_Timer_Expired(0) != 1) return;

    switch (state) {
        case INIT:
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;
        case LED_ON:
            state = LED_OFF;
            digitalWrite(GPIO_NUM_48, 0);
            break;
        case LED_OFF:
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;
    }
}
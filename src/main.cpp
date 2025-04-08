#include "software_timer.h"
#include "scheduler.h"
#include "state_machine.h"
#include <Arduino.h>

void TIMER_ISR(void *pvParameters) {
  while(1) {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup() {
  SCH_Init();
  SCH_Add_Task(Timer_Run, 0, 1);
  SCH_Add_Task(StateMachine_Run, 0, 1);
}

void loop() {
  SCH_Dispatch_Tasks();
}
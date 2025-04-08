#include "software_timer.h"
#include "scheduler.h"
#include "state_machine.h"
#include <Arduino.h>

void setup() {
  SCH_Init();
  SCH_Add_Task(Timer_Run, 0, 1);
  SCH_Add_Task(StateMachine_Run, 0, 1);
}

void loop() {
  SCH_Update();
  SCH_Dispatch_Tasks();
  delay(100);
}
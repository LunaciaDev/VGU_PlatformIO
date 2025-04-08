#include "software_timer.h"
#include "scheduler.h"
#include "state_machine.h"

#define D3 6
#define D4 7
#define D5 8
#define D6 9

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

void Timer_Tasks(void) {
  SCH_Update();
}

void setup() {
  Init_Timer();
  SCH_Init();
  StateMachine_Init();
  SCH_Add_Task(StateMachine_Run, 0, 100);
}

void loop() {
  SCH_Dispatch_Tasks();
}
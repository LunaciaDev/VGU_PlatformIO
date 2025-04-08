#include <Arduino.h>
#include "scheduler.h"

#define D3 6
#define D4 7
#define D5 8
#define D6 9

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

void setLightSet1(int light) {
  switch (light) {
    case RED_LIGHT:
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH);
      break;
    case YELLOW_LIGHT:
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);
      break;
    case GREEN_LIGHT:
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);
      break;
  }
}

void setLightSet2(int light) {
  switch (light) {
    case RED_LIGHT:
      digitalWrite(D5, HIGH);
      digitalWrite(D6, HIGH);
      break;
    case YELLOW_LIGHT:
      digitalWrite(D5, LOW);
      digitalWrite(D6, HIGH);
      break;
    case GREEN_LIGHT:
      digitalWrite(D5, HIGH);
      digitalWrite(D6, LOW);
      break;
  }
}

int count = 0;
void task1() {
  switch (count) {
      case 0:
          setLightSet1(RED_LIGHT);
          setLightSet2(GREEN_LIGHT);
          break;

      case 3:
          setLightSet2(YELLOW_LIGHT);
          break;

      case 5:
          setLightSet1(GREEN_LIGHT);
          setLightSet2(RED_LIGHT);
          break;

      case 8:
          setLightSet1(YELLOW_LIGHT);
          break;
  }

  count = (count + 1) % 10;
}

void TIMER_ISR(void *pvParameters) {
  while (1) {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup() {
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);
  // first light group
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  // second light group
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  // init scheduler
  SCH_Init();
  SCH_Add_Task(task1, 0, 100);
}

void loop() {
  SCH_Dispatch_Tasks();
}
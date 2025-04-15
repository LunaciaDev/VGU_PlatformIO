#include "software_timer.h"
#include "scheduler.h"
#include <Arduino.h>
#include "two_toggling_led.h"
#include "multiple_blinking_led.h"
#include "led_blinky.h"
#include "traffic_light.h"
#include "clock.h"

void TIMER_ISR(void *pvParameters)
{
  while (1)
  {
    SCH_Update();
    vTaskDelay(10);
  }
}

void setup()
{
  SCH_Init();
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);
  SCH_Add_Task(SoftwareTimer_Run, 0, 1);
  SCH_Add_Task(LED_Blinky, 0, 100);

  // Lab1: Two Toggling Led
  /*
  pinMode(TwoTogglingLed_Pin, OUTPUT);
  pinMode(TwoTogglingLed_Pin + 1, OUTPUT);
  SCH_Add_Task(TwoTogglingLed_Run, 0, 1);
  */

  // Lab2: Multiple Blinking Led
  /*
  pinMode(MultipleBlinkingLed_p1, OUTPUT);
  pinMode(MultipleBlinkingLed_p1 + 1, OUTPUT);
  pinMode(MultipleBlinkingLed_p2, OUTPUT);
  pinMode(MultipleBlinkingLed_p2 + 1, OUTPUT);
  pinMode(MultipleBlinkingLed_p3, OUTPUT);
  pinMode(MultipleBlinkingLed_p3 + 7, OUTPUT);
  SCH_Add_Task(MultipleBlinkingLed_Run, 0, 100);
  */

  // Lab5: 2-way Traffic Light
  
  pinMode(TrafficLight_p1, OUTPUT);
  pinMode(TrafficLight_p2, OUTPUT);
  pinMode(TrafficLight_p1+1, OUTPUT);
  pinMode(TrafficLight_p2+1, OUTPUT);
  SCH_Add_Task(TrafficLight_Run, 0, 1);
  

  // Lab6: Clock (Second Hand only?)
  /*
  pinMode(Clock_p1, OUTPUT);
  pinMode(Clock_p2, OUTPUT);
  pinMode(Clock_p3, OUTPUT);
  pinMode(Clock_p4, OUTPUT);
    
  pinMode(Clock_p1 + 1, OUTPUT);
  pinMode(Clock_p2 + 1, OUTPUT);
  pinMode(Clock_p3 + 7, OUTPUT);
  pinMode(Clock_p4 + 3, OUTPUT);
  SCH_Add_Task(Clock_Run, 0, 100);
  */
}

void loop()
{
  SCH_Dispatch_Tasks();
}
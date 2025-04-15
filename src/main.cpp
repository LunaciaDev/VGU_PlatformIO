#include "software_timer.h"
#include "scheduler.h"
#include "led_blinky.h"
#include "htsensor.h"
#include "humidifier.h"
#include "cooler.h"
#include "heater.h"
#include <Arduino.h>

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
  Serial.begin(115200);
  if (!HTSensor_Init())
  {
    Serial.println("Failed to connect to the sensor");
    return;
  }

  Serial.println("Sensor connected.");

  // prepare the pins
  pinMode(Heater_Pin, OUTPUT);
  pinMode(Heater_Pin + 1, OUTPUT);
  pinMode(Cooler_Pin, OUTPUT);
  pinMode(Cooler_Pin + 1, OUTPUT);
  pinMode(Humidifier_Pin, OUTPUT);
  pinMode(Humidifier_Pin + 1, OUTPUT);

  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);

  SCH_Init();
  SCH_Add_Task(Timer_Run, 0, 1);
  SCH_Add_Task(LED_Blinky, 0, 100);
  SCH_Add_Task(HTSensor_Read, 0, 500);
  SCH_Add_Task(Humidifier_Run, 0, 1);
  SCH_Add_Task(Heater_Run, 0, 100);
  SCH_Add_Task(Cooler_Run, 0, 1);
}

void loop()
{
  SCH_Dispatch_Tasks();
}
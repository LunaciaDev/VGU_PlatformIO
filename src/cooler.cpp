#include "cooler.h"
#include "software_timer.h"
#include "htsensor.h"
#include "light_control.h"

#define COOLER_INIT 0
#define COOLER_READY 1
#define COOLER_RUNNING 2

static const int Runtime = 500;
static const int timerSlot = 1;
static const float TemperatureThreshold = 42;
static int state = COOLER_INIT;

void Cooler_Run(void) {
    switch (state) {
        case COOLER_INIT: {
            LightControl_SetLight(Cooler_Pin, NO_LIGHT);
            state = COOLER_READY;
            break;
        }

        case COOLER_READY: {
            float temp = HTSensor_GetTemperature();

            // prevent init value
            if (temp == -1) return;

            if (temp >= TemperatureThreshold) {
                state = COOLER_RUNNING;
                LightControl_SetLight(Cooler_Pin, GREEN_LIGHT);
                Timer_Set(timerSlot, Runtime);
            }

            break;
        }

        case COOLER_RUNNING: {
            if (Timer_IsExpired(timerSlot) != 1) return;

            state = COOLER_READY;
            LightControl_SetLight(Cooler_Pin, NO_LIGHT);
        }
    }
}
#include "heater.h"
#include "htsensor.h"
#include "light_control.h"

static const float safe_threshold = 37.0;
static const float caution_threshold = 42.0;

// (-, 37]: safe
// (37, 42]: caution
// (42, +): no good?

#define HEATER_READY 1
#define HEATER_INIT 0

static int state = HEATER_INIT;

void Heater_Run(void) {
    switch (state) {
        case HEATER_INIT: {
            LightControl_SetLight(Heater_Pin, NO_LIGHT);
            state = HEATER_READY;
            break;
        }

        case HEATER_READY: {
            float temp = HTSensor_GetTemperature();
            // block init value
            if (temp == -1) return;

            if (temp <= safe_threshold) {
                LightControl_SetLight(Heater_Pin, GREEN_LIGHT);
                return;
            }

            if (temp <= caution_threshold) {
                LightControl_SetLight(Heater_Pin, YELLOW_LIGHT);
                return;
            }

            LightControl_SetLight(Heater_Pin, RED_LIGHT);
        }
    }
}
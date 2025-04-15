#include "humidifier.h"
#include "htsensor.h"
#include "light_control.h"
#include "software_timer.h"

#define HUMIDIFIER_INIT 0
#define HUMIDIFIER_READY 1
// Green LED for 5s
#define HUMIDIFIER_STAGE_1 2
// Yellow LED for 3s
#define HUMIDIFIER_STAGE_2 3
// Red LED for 2s
#define HUMIDIFIER_STAGE_3 4

static const int TIMER_SLOT = 0;
static const int STAGE_1_TIMER = 500;
static const int STAGE_2_TIMER = 300;
static const int STAGE_3_TIMER = 200;
static const float HUMIDITY_THRESHOLD = 0.55;

static int current_state = HUMIDIFIER_READY;

void Humidifier_Run(void) {
    switch (current_state) {
        case HUMIDIFIER_INIT: {
            current_state = HUMIDIFIER_READY;
            LightControl_SetLight(Humidifier_Pin, NO_LIGHT);
        }

        case HUMIDIFIER_READY: {
            float humidity = HTSensor_GetHumidity();

            // prevent uninitialized value
            if (humidity == -1) return;

            if (HTSensor_GetHumidity() < HUMIDITY_THRESHOLD) {
                current_state = HUMIDIFIER_STAGE_1;
                Timer_Set(TIMER_SLOT, STAGE_1_TIMER);
                LightControl_SetLight(Humidifier_Pin, GREEN_LIGHT);
            }

            break;
        }

        case HUMIDIFIER_STAGE_1: {
            if (Timer_IsExpired(TIMER_SLOT) != 1) return;

            current_state = HUMIDIFIER_STAGE_2;
            Timer_Set(TIMER_SLOT, STAGE_2_TIMER);
            LightControl_SetLight(Humidifier_Pin, YELLOW_LIGHT);
            break;
        }

        case HUMIDIFIER_STAGE_2: {
            if (Timer_IsExpired(TIMER_SLOT) != 1) return;

            current_state = HUMIDIFIER_STAGE_3;
            Timer_Set(TIMER_SLOT, STAGE_3_TIMER);
            LightControl_SetLight(Humidifier_Pin, RED_LIGHT);
            break;
        }

        case HUMIDIFIER_STAGE_3: {
            if (Timer_IsExpired(TIMER_SLOT) != 1) return;

            current_state = HUMIDIFIER_READY;
            LightControl_SetLight(Humidifier_Pin, NO_LIGHT);
            break;
        }
    }
}


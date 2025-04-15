#include "two_toggling_led.h"
#include "light_controller.h"
#include "software_timer.h"

#define Lab1_Init 0
#define Lab1_RedOn 1
#define Lab1_YellowOn 2

static int current_state = Lab1_Init;
const static int timer_slot = 0;
const static int delay = 200;

void TwoTogglingLed_Run(void) {
    switch (current_state) {
        case Lab1_Init: {
            LightController_Set(TwoTogglingLed_Pin, RED_LIGHT);
            current_state = Lab1_RedOn;
            SoftwareTimer_Set(timer_slot, delay);
            break;
        }

        case Lab1_RedOn: {
            if (SoftwareTimer_IsExpired(timer_slot) != 1) break;

            current_state = Lab1_YellowOn;
            LightController_Set(TwoTogglingLed_Pin, YELLOW_LIGHT);
            SoftwareTimer_Set(timer_slot, delay);
        }

        case Lab1_YellowOn: {
            if (SoftwareTimer_IsExpired(timer_slot) != 1) break;

            current_state = Lab1_RedOn;
            LightController_Set(TwoTogglingLed_Pin, RED_LIGHT);
            SoftwareTimer_Set(timer_slot, delay);
        }
    }
}
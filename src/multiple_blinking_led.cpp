#include "multiple_blinking_led.h"
#include "light_controller.h"

static int current_state = 0;

void MultipleBlinkingLed_Run(void) {
    switch(current_state) {
        case 0: {
            current_state = 1;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 1: {
            current_state = 2;
            LightController_Set(MultipleBlinkingLed_p1, RED_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 2: {
            current_state = 3;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, RED_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 3: {
            current_state = 4;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, RED_LIGHT);
            break;
        }

        case 4: {
            current_state = 5;
            LightController_Set(MultipleBlinkingLed_p1, YELLOW_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 5: {
            current_state = 6;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, YELLOW_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 6: {
            current_state = 7;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, YELLOW_LIGHT);
            break;
        }

        case 7: {
            current_state = 8;
            LightController_Set(MultipleBlinkingLed_p1, GREEN_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 8: {
            current_state = 9;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, GREEN_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, NO_LIGHT);
            break;
        }

        case 9: {
            current_state = 0;
            LightController_Set(MultipleBlinkingLed_p1, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p2, NO_LIGHT);
            LightController_Set(MultipleBlinkingLed_p3, GREEN_LIGHT);
            break;
        }
    }
}
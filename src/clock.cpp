#include "clock.h"
#include "light_controller.h"

static int time = 0;

void Clock_Run(void) {
    time = (time + 1) % 60;

    switch (time / 5) {
        case 0: {
            LightController_Set(Clock_p1, RED_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 1: {
            LightController_Set(Clock_p1, YELLOW_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 2: {
            LightController_Set(Clock_p1, GREEN_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 3: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, RED_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 4: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, YELLOW_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 5: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, GREEN_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 6: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, RED_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 7: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, YELLOW_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }
        
        case 8: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, GREEN_LIGHT);
            LightController_Set(Clock_p4, NO_LIGHT);
            break;
        }

        case 9: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, RED_LIGHT);
            break;
        }

        case 10: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, YELLOW_LIGHT);
            break;
        }

        case 11: {
            LightController_Set(Clock_p1, NO_LIGHT);
            LightController_Set(Clock_p2, NO_LIGHT);
            LightController_Set(Clock_p3, NO_LIGHT);
            LightController_Set(Clock_p4, GREEN_LIGHT);
            break;
        }
    }
}
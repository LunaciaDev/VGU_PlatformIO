#include "traffic_light.h"
#include "light_controller.h"
#include "software_timer.h"

#define TrafficLight_Init 0
#define TrafficLight_RG 1
#define TrafficLight_RY 2
#define TrafficLight_GR 3
#define TrafficLight_YR 4

const static int yellowDuration = 200;
const static int greenDuration = 300;
// red = yellow + green
const static int timerSlot = 1;

static int currentState = TrafficLight_Init;

void TrafficLight_Run(void) {
    switch (currentState) {
        case TrafficLight_Init: {
            LightController_Set(TrafficLight_p1, RED_LIGHT);
            LightController_Set(TrafficLight_p2, GREEN_LIGHT);
            SoftwareTimer_Set(timerSlot, greenDuration);
            currentState = TrafficLight_RG;
            break;
        }

        case TrafficLight_RG: {
            if (SoftwareTimer_IsExpired(timerSlot) != 1) break;

            LightController_Set(TrafficLight_p2, YELLOW_LIGHT);
            SoftwareTimer_Set(timerSlot, yellowDuration);
            currentState = TrafficLight_RY;
            break;
        }

        case TrafficLight_RY: {
            if (SoftwareTimer_IsExpired(timerSlot) != 1) break;

            LightController_Set(TrafficLight_p1, GREEN_LIGHT);
            LightController_Set(TrafficLight_p2, RED_LIGHT);
            SoftwareTimer_Set(timerSlot, greenDuration);
            currentState = TrafficLight_GR;
            break;
        }

        case TrafficLight_GR: {
            if (SoftwareTimer_IsExpired(timerSlot) != 1) break;

            LightController_Set(TrafficLight_p1, YELLOW_LIGHT);
            SoftwareTimer_Set(timerSlot, yellowDuration);
            currentState = TrafficLight_YR;
            break;
        }

        case TrafficLight_YR: {
            if (SoftwareTimer_IsExpired(timerSlot) != 1) break;

            LightController_Set(TrafficLight_p1, RED_LIGHT);
            LightController_Set(TrafficLight_p2, GREEN_LIGHT);
            SoftwareTimer_Set(timerSlot, greenDuration);
            currentState = TrafficLight_RG;
            break;
        }
    }
}
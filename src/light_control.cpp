#include "light_control.h"
#include "Arduino.h"

void LightControl_SetLight(int target, int light)
{
    switch (light)
    {
        case RED_LIGHT:
            digitalWrite(target, HIGH);
            digitalWrite(target+1, HIGH);
            break;

        case YELLOW_LIGHT:
            digitalWrite(target, LOW);
            digitalWrite(target+1, HIGH);
            break;

        case GREEN_LIGHT:
            digitalWrite(target, HIGH);
            digitalWrite(target+1, LOW);
            break;

        case NO_LIGHT:
            digitalWrite(target, LOW);
            digitalWrite(target+1, LOW);
            break;
    }
}
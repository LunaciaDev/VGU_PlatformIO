#include "light_control.h"
#include "Arduino.h"

void LightControl_SetLight(int pin, int light)
{
    if (pin == 10)
    {
        switch (light)
        {
        case RED_LIGHT:
            digitalWrite(pin, HIGH);
            digitalWrite(pin + 7, HIGH);
            break;

        case YELLOW_LIGHT:
            digitalWrite(pin, LOW);
            digitalWrite(pin + 7, HIGH);
            break;

        case GREEN_LIGHT:
            digitalWrite(pin, HIGH);
            digitalWrite(pin + 7, LOW);
            break;

        case NO_LIGHT:
            digitalWrite(pin, LOW);
            digitalWrite(pin + 7, LOW);
            break;
        }

        return;
    }

    switch (light)
    {
    case RED_LIGHT:
        digitalWrite(pin, HIGH);
        digitalWrite(pin + 1, HIGH);
        break;

    case YELLOW_LIGHT:
        digitalWrite(pin, LOW);
        digitalWrite(pin + 1, HIGH);
        break;

    case GREEN_LIGHT:
        digitalWrite(pin, HIGH);
        digitalWrite(pin + 1, LOW);
        break;

    case NO_LIGHT:
        digitalWrite(pin, LOW);
        digitalWrite(pin + 1, LOW);
        break;
    }
}
#include "light_controller.h"
#include "Arduino.h"

void LightController_Set(int pin, int light) {
    if (pin == 10) {
        switch (light) {
            case RED_LIGHT:
                digitalWrite(pin, HIGH);
                digitalWrite(17, HIGH);
                break;
    
            case YELLOW_LIGHT:
                digitalWrite(pin, LOW);
                digitalWrite(17, HIGH);
                break;
    
            case GREEN_LIGHT:
                digitalWrite(pin, HIGH);
                digitalWrite(17, LOW);
                break;
    
            case NO_LIGHT:
                digitalWrite(pin, LOW);
                digitalWrite(17, LOW);
                break;
        }

        return;
    }

    if (pin == 18) {
        switch (light) {
            case RED_LIGHT:
                digitalWrite(pin, HIGH);
                digitalWrite(21, HIGH);
                break;
    
            case YELLOW_LIGHT:
                digitalWrite(pin, LOW);
                digitalWrite(21, HIGH);
                break;
    
            case GREEN_LIGHT:
                digitalWrite(pin, HIGH);
                digitalWrite(21, LOW);
                break;
    
            case NO_LIGHT:
                digitalWrite(pin, LOW);
                digitalWrite(21, LOW);
                break;
        }
    }

    switch (light) {
        case RED_LIGHT:
            digitalWrite(pin, HIGH);
            digitalWrite(pin+1, HIGH);
            break;

        case YELLOW_LIGHT:
            digitalWrite(pin, LOW);
            digitalWrite(pin+1, HIGH);
            break;

        case GREEN_LIGHT:
            digitalWrite(pin, HIGH);
            digitalWrite(pin+1, LOW);
            break;

        case NO_LIGHT:
            digitalWrite(pin, LOW);
            digitalWrite(pin+1, LOW);
            break;
    }
}
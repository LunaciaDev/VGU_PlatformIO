#ifndef __LIGHT_CONTROLLER_H__
#define __LIGHT_CONTROLLER_H__

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define NO_LIGHT 3

void LightController_Set(int pin, int light);

#endif
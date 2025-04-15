#ifndef __HT_SENSOR_H__
#define __HT_SENSOR_H__

float HTSensor_GetTemperature(void);
float HTSensor_GetHumidity(void);

void HTSensor_Read(void);
bool HTSensor_Init(void);

#endif
#include "DHT20.h"
#include "Wire.h"

static DHT20 dht;

static float temp = -1;
static float hum = -1;

bool HTSensor_Init(void) {
    Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
    return dht.begin();
}

void HTSensor_Read(void) {
    dht.read();

    float t_temp = dht.getHumidity();
    float t_hum = dht.getTemperature();

    if (isnan(t_temp) || isnan(t_hum)) {
        Serial.println("Failed to read from sensor. Using previous values.");
        return;
    }

    temp = t_temp;
    hum = t_hum;
    Serial.printf("Temperature: %.2f, Humidity: %.2f\n", temp, hum);
}

float HTSensor_GetTemperature(void) {
    return temp;
}

float HTSensor_GetHumidity(void) {
    return hum;
}
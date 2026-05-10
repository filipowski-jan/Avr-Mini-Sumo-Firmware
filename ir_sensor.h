#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <avr/io.h>
#include <stdbool.h>

// Infrared Sensor Pin
#define SENSOR_OUT PC1

void ir_sensor_init(void);
bool ir_sensor_read(void);

#endif
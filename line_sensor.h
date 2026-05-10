#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include <avr/io.h>

void line_sensor_init(void);
uint16_t line_sensor_read(void);

#endif
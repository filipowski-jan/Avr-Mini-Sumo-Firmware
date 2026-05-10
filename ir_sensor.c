#include "ir_sensor.h"

void ir_sensor_init(void)
{
    DDRC &= ~(1 << SENSOR_OUT);
    PORTC |= (1 << SENSOR_OUT);
}

bool ir_sensor_read(void)
{
    return !(PINC & (1 << SENSOR_OUT));
}

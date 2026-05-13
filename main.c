#include "motors.h"
#include "ir_sensor.h"
#include "line_sensor.h"
#include <util/delay.h>

// PWM value 0–255 (255 = full speed)
#define MOTOR_SPEED 255
#define MOTOR_TURNING_SPEED 200

// Line sensor threshold
#define LINE_THRESHOLD 500

int main(void)
{
    motors_init();
    ir_sensor_init();
    line_sensor_init();
    _delay_ms(300);

    while (1)
    {
        // Retreat if robot left the arena
        if (line_sensor_read() < LINE_THRESHOLD)
        {
            motor_left_backward(MOTOR_SPEED);
            motor_right_backward(MOTOR_SPEED);
            _delay_ms(75);
            motors_stop();
        }
        // Charge if enemy detected
        else if (ir_sensor_read())
        {
            motor_left_forward(MOTOR_SPEED);
            motor_right_forward(MOTOR_SPEED);
        }
        // Searching for enemy
        else
        {
            motor_left_forward(MOTOR_TURNING_SPEED);
            motor_right_backward(MOTOR_TURNING_SPEED);
            _delay_ms(10);
            motors_stop();
            _delay_ms(20);
        }
    }
}
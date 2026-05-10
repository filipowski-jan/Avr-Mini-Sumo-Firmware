#ifndef MOTORS_H
#define MOTORS_H

#include <avr/io.h>

// Motor direction pins
#define LEFT_IN1 PD0
#define LEFT_IN2 PD1
#define RIGHT_IN3 PD3
#define RIGHT_IN4 PD2
// Motor speed pins
#define LEFT_SPEED PB1
#define RIGHT_SPEED PB2

void motors_init(void);
void motor_left_forward(uint8_t speed);
void motor_right_forward(uint8_t speed);
void motor_left_backward(uint8_t speed);
void motor_right_backward(uint8_t speed);
void motors_stop(void);

#endif
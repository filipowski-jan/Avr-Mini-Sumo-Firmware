#include "motors.h"

void motors_init(void)
{
    DDRD |= (1 << LEFT_IN1) | (1 << LEFT_IN2) | (1 << RIGHT_IN3) | (1 << RIGHT_IN4);
    DDRB |= (1 << LEFT_SPEED) | (1 << RIGHT_SPEED);

    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
    TCCR1B = (1 << WGM12) | (1 << CS11);
}

void motor_left_forward(uint8_t speed)
{
    PORTD &= ~(1 << LEFT_IN1);
    PORTD |=  (1 << LEFT_IN2);
    OCR1A = speed;
}

void motor_right_forward(uint8_t speed)
{
    PORTD &= ~(1 << RIGHT_IN3);
    PORTD |=  (1 << RIGHT_IN4);
    OCR1B = speed;
}

void motor_left_backward(uint8_t speed)
{
    PORTD |=  (1 << LEFT_IN1);
    PORTD &= ~(1 << LEFT_IN2);
    OCR1A = speed;
}

void motor_right_backward(uint8_t speed)
{
    PORTD |=  (1 << RIGHT_IN3);
    PORTD &= ~(1 << RIGHT_IN4);
    OCR1B = speed;
}

void motors_stop(void)
{
    PORTD &= ~((1 << LEFT_IN1) | (1 << LEFT_IN2) | (1 << RIGHT_IN3) | (1 << RIGHT_IN4));
    OCR1A = 0;
    OCR1B = 0;
}

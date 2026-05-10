@echo off

avr-gcc -mmcu=atmega8 -DF_CPU=16000000UL -Os ^
    main.c motors.c sensors.c ir_sensor.c line_sensor.c ^
    -o main.elf

avr-objcopy -O ihex main.elf main.hex
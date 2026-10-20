# Avr Mini Sumo Firmware

Firmware for an AVR-based mini sumo robot built around an ATmega8 running at 16 MHz.

## Behavior

The control loop in `main.c` follows this strategy:

- If the line sensor detects arena edge, the robot briefly retreats.
- If the IR sensor detects an opponent, the robot drives forward at full speed.
- Otherwise, the robot performs a search turn pattern.

## Project files

- `main.c` – main robot behavior loop.
- `motors.c` / `motors.h` – motor control functions.
- `ir_sensor.c` / `ir_sensor.h` – opponent detection sensor handling.
- `line_sensor.c` / `line_sensor.h` – arena edge detection sensor handling.

## Build

Use AVR-GCC and AVR binutils.

On Linux/macOS:

```bash
./build.sh
```

This generates:

- `main.elf`
- `main.hex`

## Flashing

Flash `main.hex` with your preferred AVR programmer (for example, `avrdude`) using settings that match your hardware.

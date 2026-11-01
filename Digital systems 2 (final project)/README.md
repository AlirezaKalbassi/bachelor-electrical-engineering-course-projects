# Digital Clock on the 8051 (AT89C51)

A digital clock for the AT89C51 microcontroller, written in 8051 assembly, assembled in Keil uVision, and simulated
in Proteus. It shows hours, minutes, and seconds on 7-segment displays and can be set with four push buttons.
Final project of the Digital Systems 2 course.

## Hardware (simulated in Proteus)

| Part | Details |
|---|---|
| Microcontroller | AT89C51, 12 MHz clock |
| Seconds output | Port P0 |
| Minutes output | Port P2 |
| Hours output | Port P3 |
| Displays | BCD 7-segment displays |
| Inputs | Four push buttons on P1.0 to P1.3, with 10 kΩ resistors |

## How it works

The program keeps the time in the three output ports and in six counter registers (units and tens of seconds,
minutes, and hours). After each delay, the main loop advances the seconds and carries into the minutes and hours
when a digit rolls over.

### Setting the time

Buttons are active-low (pressed = logic 0).

| Button | Function |
|---|---|
| P1.0 | Enter time-setting mode (the display is cleared) |
| P1.1 | Increase the selected value |
| P1.2 | Decrease the selected value |
| P1.3 | Move to the next field: hours, then minutes, then seconds, then back to running |

In setting mode, a short delay follows each button check so one press does not change the value many times.

### Timing

The time base is a software delay loop (the `DELAY` subroutine). With the 12 MHz clock configured in Proteus, one
count takes roughly half a millisecond, so the simulated clock counts much faster than real time. A real one-second
tick would need a longer delay or the 8051's Timer 0.

## Files

| File | Description |
|---|---|
| `keil/STARTUP.A51` | The program (8051 assembly) |
| `keil/project 1.uvproj` | Keil uVision project for the AT89C51 |
| `keil/Objects/project 1.hex` | Compiled program loaded by the simulation |
| `proteus/Project.pdsprj` | Proteus schematic |

## Run it

1. Open `proteus/Project.pdsprj` in Proteus 8.
2. Start the simulation and use the push buttons to set the time.

The AT89C51 loads the program from `..\keil\Objects\project 1.hex`, so keep the `keil` and `proteus` folders side by
side. If Proteus cannot find the file, double-click the microcontroller and set **Program File** to that `.hex` file.

To rebuild the program, open `keil/project 1.uvproj` in Keil uVision and build the target.

## Tools

- Keil uVision (assembler and linker)
- Proteus (circuit simulation)

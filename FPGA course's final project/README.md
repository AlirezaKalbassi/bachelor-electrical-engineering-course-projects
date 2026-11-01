# UART Receiver with 7-Segment Display (FPGA)

A Verilog design that receives three characters over a serial (UART) line and shows them on a multiplexed
three-digit 7-segment display. It targets a Xilinx Spartan-6 FPGA (XC6SLX9, FTG256) and was built with Xilinx ISE.
Final project of the FPGA course.

## How it works

```
rx ──► UART receiver (FSM) ──► 3-character buffer ──► ASCII to 7-segment decoder ──► digit multiplexer ──► display
```

### UART receiver

- A finite state machine moves through idle, start bit, eight data bits (least significant bit first), and stop bit.
- A counter sets the bit period to `n = 5208` clock cycles, which is **9600 baud with a 50 MHz clock**. Each data bit is sampled in the middle of its period.
- The frame format is 8 data bits, no parity, 1 stop bit (8N1).
- Received characters are collected in a three-byte buffer. After the third character, the buffer is copied to the output registers, so the display updates once per three characters.

### 7-segment decoder

- A lookup table converts ASCII codes to segment patterns for the digits **0-9**, lowercase letters **a-z**, and uppercase letters **A-Z**.
- Segments are active-low. Bit 7 drives the decimal point.
- An uppercase letter uses the same pattern as its lowercase letter with the **decimal point lit**, so the two can be told apart.

### Display multiplexing

Three of the six digit-select lines are used. The three digits are enabled one after another, each for 1,000 clock
cycles, so they all look lit at the same time.

## Interface

| Signal | Direction | Description |
|---|---|---|
| `clk` | in | Board clock (50 MHz assumed) |
| `rst` | in | Reset, active-low |
| `rx` | in | Serial data input |
| `d[7:0]` | out | Segment lines `a` to `g` and the decimal point |
| `s[5:0]` | out | Digit-select lines, active-low (three used) |

Pin assignments are in `project_implement.ucf`.

## Files

| File | Description |
|---|---|
| `project.v` | Main design: UART receiver, decoder, and display multiplexer |
| `project_t.v` | Testbench: drives a 50 MHz clock, a reset, and some `rx` activity |
| `project_implement.ucf` | Pin constraints |
| `project.xise` | Xilinx ISE project file |

## Run it

**Simulation**
1. Open `project.xise` in Xilinx ISE.
2. Select `project_t.v` and run the behavioral simulation (ISim).

**On hardware**
1. Check the pin assignments in `project_implement.ucf` and adjust them if your board is different.
2. Synthesize, implement, and generate the bitstream in ISE, then program the FPGA.
3. Connect the `rx` pin to the TX pin of a USB-serial adapter and open a serial terminal at 9600 baud, 8N1.
4. Send three characters (for example `A1b`). They appear on the three digits after the third one arrives.

## Tools

- Verilog HDL
- Xilinx ISE (synthesis and ISim simulation)

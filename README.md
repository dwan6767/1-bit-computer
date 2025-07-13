# 1-bit-computer
![lablledpicture](https://github.com/user-attachments/assets/c20e71e7-5ede-4cbc-841c-578488daa07e)

🧠 1-Bit CPU Emulator & Hardware Build

This project is a custom 1-bit computer, built from scratch using logic gates, flip-flops, and transistors — backed by a terminal emulator that mimics the real hardware.

    Fully documented, manually wired, and mentally brutal — no microcontrollers, no BS. Just logic.

📦 Features

    1-bit Registers: A & B (real or simulated)

    4x4 ROM: 4 instructions, 4-bit wide each

    Opcode Format: H I S D (1-bit each)

    Terminal Emulator in C

    Blinking LED Output via terminal or real register output

    Optional clock selection by user

    Full hardware logic implemented with:

        Diodes for ROM

        74LS series gates for control logic

        Transistor logic for registers, mux, and counters

* Instruction Format

Each instruction is 4 bits:

| Bit 3 | Bit 2 | Bit 1 | Bit 0 |
|   D   |   S   |   I   |   H   |

Bit	Name	Description

3	D	Destination (0 = A, 1 = B)

2	S	Source or Value (0/1 or reg select)

1	I	0 = COPY reg, 1 = LOAD immediate
0	H	HALT if set


*Supported Instructions

Instruction	Binary	Decimal	Meaning
LOAD 1 → A	
0110	6	A = 1
LOAD 0 → A
	0010	2	A = 0
COPY A → B	
1000	8	B = A
COPY B → A	
0100	4	A = B
COPY A → A + HALT
	0001	1	A stays same, CPU halts

# 1-bit-computer
![lablledpicture](https://github.com/user-attachments/assets/c20e71e7-5ede-4cbc-841c-578488daa07e)

 1-Bit CPU Emulator & Hardware Build

#  1-Bit Logic Gate Computer

A minimalist 1-bit CPU built using logic gate ICs. It uses diode-ROM and a 2-bit program counter. All logic is hardwired.

## Architecture

- **Registers**:  
  - A = address 0  
  - B = address 1
- **Instruction format**: `[I][H][A2][A1]` (4-bit)
- **ROM**: 4×4-bit (diode-based)
- **PC**: 2-bit counter

##  Instructions

| I | H | A2 | A1 | Meaning                   |
|---|---|----|----|---------------------------|
| 0 | 0 | dst | src | COPY: src → dst         |
| 1 | 0 | dst | val | LOAD: val (0/1) → dst   |
| * | 1 |  *  |  *  | HALT after execution     |

## ⚙ Execution Flow

1. Fetch 4-bit instruction from ROM[PC]  
2. Decode and execute:  
   - If `I = 0`: Copy `A1` → `A2`  
   - If `I = 1`: Load value `A1` → `A2`  
3. Increment PC  
4. Halt if `H = 1`

##  Built With

- Logic gate ICs (7400, 7404, 7432, etc.)  
- D flip-flops for registers and PC  
- Diode matrix ROM  
- LEDs for visual debugging

##  Sample Program

| Addr | I H A2 A1 | Binary | Description         |
|------|-----------|--------|---------------------|
| 0    | 1 1 0 1   | `1101` | Load 1 → A, halt    |
| 1    | 0 0 1 0   | `0010` | Copy A → B          |
| 2    | 0 0 0 1   | `0001` | Copy B → A          |
| 3    | 0 0 0 0   | `0000` | Copy A → A (noop)   |

## Supported Instructions

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

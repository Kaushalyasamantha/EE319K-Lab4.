# EE319K Lab 4: Digital I/O and Logic Implementation
**Embedded Systems: Shape of the World**

## 1. Project Overview
This project implements the digital control logic for a TM4C123 microcontroller to interface with switches and an RGB LED. The software is designed to read inputs from two switches and drive a multi-color LED based on specific logic requirements.

## 2. Hardware Architecture
The system utilizes **Memory-Mapped I/O** to interact with the microcontroller hardware.

* **Microcontroller**: TM4C123
* **I/O Port**: GPIO Port F
* **Data Register Address**: `0x400253FC`

### Pin Mapping
| Component | Pin | Logic Type |
| :--- | :--- | :--- |
| **Switch 1 (SW1)** | PF4 | Negative Logic (0V = Pressed) |
| **Switch 2 (SW2)** | PF0 | Negative Logic (0V = Pressed) |
| **Red LED** | PF1 | Positive Logic (3.3V = ON) |
| **Blue LED** | PF2 | Positive Logic (3.3V = ON) |
| **Green LED** | PF3 | Positive Logic (3.3V = ON) |



## 3. Logic Specifications
The system follows the functional requirements defined in the Lab 4 truth table:

| Input Condition | LED Output | Register Write Value |
| :--- | :--- | :--- |
| **Both SW1 and SW2 pressed** | **Blue** | `0x04` |
| **Only SW1 pressed** | **Red** | `0x02` |
| **Only SW2 pressed** | **Green** | `0x08` |
| **Neither switch pressed** | **OFF** | `0x00` |

## 4. Implementation Details
* **Bit-Masking**: Used `& 0x11` to isolate input pins PF4 and PF0.
* **Control Flow**: Implemented a non-terminating `while(1)` loop as required for embedded real-time systems.
* **Environment**: Developed in **VS Code** and verified using the **Wokwi Online Simulator**.


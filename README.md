# CAN - based Vehicle Control System using LPC2129 
AIM: The main AIM of this project is to display the Engine Temperature, Reverse Alert and Control the Door Glass windows using CAN protocol.

## Hardware Requirement
* LPC2129
* CAN Transceiver MCP2551
* GP2D12 distance sensor
* DS18B20 temperature sensor
* 16x2 LCD
* LEDs (8)
* Buzzer
* Switches
* USB to UART converter
## Software Requirements
* Keil C compiler
* Flash magic
* Embedded C programming
## Workflow
### MAIN node
#### It reads the Engine Temperature through DS18B20 sensor using 1-wire protocol
#### Three switches connected to this node.
SW1: To increase the window glass level
SW2: To decrease the window glass level
SW3: To toggle vehicle direction Forward (or) Reverse
All three switches works on Interrupts.

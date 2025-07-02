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
#### 16x2 LCD displays Temperature and Vehicle Direction
#### Three switches connected to this node.
* SW1: To increase the window glass level

    Closes window in 8 levels
* SW2: To decrease the window glass level

    Opens window in 8 levels
* SW3: To toggle vehicle direction Forward (or) Reverse

    In reverse mode, it receives the object distance and displays on the LCD

    If object distance is within the predefined limits then it gives an alert via Buzzer
* All three switches works on Interrupts.

### REVERSE node
#### It has GP2D12 sensor and this sensor continuously calculates the nearest object distance and sends the data to MAIN node via CAN 
### WINDOW node
### This node has 8 active low LEDs. According to the data received from the MAIN node SW1 and SW2, it lights up the LEDs


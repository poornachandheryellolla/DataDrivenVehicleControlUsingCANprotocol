#ifndef _LCD__DEFINES_H

#define _LCD__DEFINES_H

// HD44780 Commands

#define CLEAR_LCD          0x01

#define RET_CUR_HOME       0x02

#define SHIFT_CUR_RIGHT    0x14

#define SHIFT_CUR_LEFT     0x10

#define DSP_OFF            0x08

#define DSP_ON_CUR_OFF     0x0C

#define DSP_ON_CUR_ON      0x0E

#define DSP_ON_CUR_BLINK   0x0F

#define SHIFT_DSP_LEFT     0x18

#define SHIFT_DSP_RIGHT    0x1C

#define MODE_8BIT_1LINE    0x30

#define MODE_8BIT_2LINE    0x38

#define MODE_4BIT_1LINE    0x20

#define MODE_4BIT_2LINE    0x28

#define GOTO_LINE1_POS0    0x80

#define GOTO_LINE2_POS0    0xC0

#define GOTO_LINE3_POS0    0x94

#define GOTO_LINE4_POS0    0xD4

#define GOTO_CGRAM_START   0x40

#define LCD_DATA            8  // P0.0-P0.7

#define LCD_RS              16

#define LCD_EN              17

#define LCD_RW              19


#endif


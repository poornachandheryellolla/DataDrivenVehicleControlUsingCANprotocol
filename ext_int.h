//ext_int.h


#define EI0 1

#define EI1 3

#define EI2 7


#define EI0_CH 14

#define EI1_CH 15

#define EI2_CH 16


void Enable_Interrupts(void);

void Toggle_Gear(void)__irq;

void Window_Close(void)__irq;

void Window_Open(void)__irq;


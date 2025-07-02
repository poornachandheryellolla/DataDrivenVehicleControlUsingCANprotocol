#include "types.h"

#ifndef _LCD_H_

#define _LCD_H_

void WriteLCD(u8);

void CmdLCD(u8);

void InitLCD(void);

void CharLCD(u8);

void SetCursor(u8,u8);

void StrLCD(s8 *);

void U32LCD(u32);

void S32LCD(s32);

void F32LCD(f32,u8);

void BuildCGRAM(u8*,u16); 

void sample(void);

#endif


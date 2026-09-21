#ifndef KEYPAD_H
#define KEYPAD_H
#include"types.h"
void INIT_KPM(void);
u32 RowCheck(void);
u32 ColCheck(void);
u32 KeyScan(void);
u32 colscan(void);
u32 ReadNum(void);
#endif
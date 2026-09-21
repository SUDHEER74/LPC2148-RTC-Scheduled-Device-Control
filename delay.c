//delay.c
#include "types.h"

void delay_us(u32 delayus)
{
    for(delayus *= 12; delayus > 0; delayus--);
}

void delay_ms(u32 delayms)
{
    for(delayms *= 12000; delayms > 0; delayms--);
}

void delay_s(u32 delays)
{
    for(delays *= 12000000; delays > 0; delays--);
}


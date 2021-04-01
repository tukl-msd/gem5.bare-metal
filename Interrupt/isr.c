#include <stdio.h>

void isr(void)
{
    //Timer BaseAddress
#if GEM5_MACHINETYPE == VExpress_GEM5_V1
    int *timer1 = (int*)0x2a820000; 
#else
    int *timer1 = (int*)0x10011000; 
#endif

    //Clear Timer Interrupt Flag 
    timer1[3] = 0xff;

    printf("***************** INTERRUPT!!! *************************\n");
}

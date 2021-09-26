#include <stdio.h>

#include "timer.h"

void isr(void)
{
    //Timer BaseAddress
    int *timer1 = (int*)TIMER_BASE; 

    //Clear Timer Interrupt Flag 
    timer1[CNTP_CTL] = 0x02;

    printf("***************** INTERRUPT!!! *************************\n");
}

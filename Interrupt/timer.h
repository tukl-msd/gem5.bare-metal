/* Timer Register maps */

#if GEM5_MACHINETYPE_VExpress_GEM5_V1
    #define TIMER_BASE	0x2a820000
#else
    #define TIMER_BASE	0x10011000
#endif

//offsets
#define CNTP_CTL	11
#define CNTP_TVAL	10

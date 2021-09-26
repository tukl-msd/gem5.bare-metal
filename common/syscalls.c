#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define UNUSED __attribute__((unused))

//GEM5_MACHINETYPE=VExpress_GEM5_V1
volatile unsigned int *const UART0DR = (unsigned int *)0x1c090000;

register char *stack_ptr __asm ("sp");

int _read_r(UNUSED struct _reent *r, UNUSED int file, UNUSED char *ptr, UNUSED int len)
{
    errno = EINVAL;
    return -1;
}

int _lseek_r(UNUSED struct _reent *r, UNUSED int file, UNUSED int ptr, UNUSED int dir)
{
    return 0;
}

int _write_r(UNUSED struct _reent *r, UNUSED int file, char *ptr, int len)
{
    int cnt;
    for (cnt = 0; cnt < len; cnt++) {
        *UART0DR = *ptr++;
    }
    return len;
}

int _close_r(struct _reent *r, int file)
{
    return 0;
}

caddr_t _sbrk_r(struct _reent *r, int incr)
{
    extern char   end __asm ("end"); 
    static char * heap_end;
    char *        prev_heap_end;

    if (heap_end == NULL)
        heap_end = & end;

    prev_heap_end = heap_end;

    if (heap_end + incr > stack_ptr)
    {
        errno = ENOMEM;
        return (caddr_t) -1;
    }

    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

int _fstat_r(UNUSED struct _reent *r, UNUSED int file, struct stat *st)
{
    memset(st, 0, sizeof (*st));
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty_r(UNUSED struct _reent *r, UNUSED int fd)
{
    return 1;
}


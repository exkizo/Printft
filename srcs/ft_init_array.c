#include "../includes/ft_printf.h"

void init_array (int (**f)(va_list args))
{
    f['s'] = prints;
    f['c'] = printc;
    f['d'] = printd;
    f['i'] = printd;
    f['u'] = printu;
    f['x'] = printx;
    f['X'] = printxx;
    f['p'] = printp;
}
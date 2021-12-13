#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int prints(va_list args)
{
    char *s = va_arg(args, char *);
    int i = 0;

    while (*s)
    {
        write(1, s++, 1);
        i++;
    }
    return (i);
}

int printc(va_list args)
{
    int c = va_arg(args, int);

    write(1, &c, 1);
    return (1);
}

void init_array (int (**f)(va_list args))
{
    f['s'] = prints;
    f['c'] = printc;
}

int ft_printchar (const char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printf(const char *str, ...)
{
    int len = 0;
    int i = 0;
    va_list args;
    int (*f[256]) (va_list args);

    va_start(args, str);
    init_array(f);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            len += (*f[str[i + 1]]) (args);
            i++;
        }
        else
            len += ft_printchar(str[i]);
        i++;
    }
    va_end(args);
    return(len);
}

int main()
{
    int len;

    len = ft_printf(" %s %c", "hello", 48);
    printf("%d", len);
    return(0);
}
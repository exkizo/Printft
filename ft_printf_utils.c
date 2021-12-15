/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:02:41 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/13 18:02:41 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

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

int printd(va_list args)
{
    int len;
    char *numstr;
    int i = 0;
    int num = va_arg(args, int);

    numstr = ft_itoa(num);
    while (numstr[i] != '\0')
    {
        write(1, &numstr[i], 1);
        i++;
    }
    free(numstr);
    return (i);
}

int printu(va_list args)
{
    int len;
    char *numstr;
    int i = 0;
    unsigned int num = va_arg(args, unsigned int);

    numstr = ft_utoa(num);
    while (numstr[i] != '\0')
    {
        write(1, &numstr[i], 1);
        i++;
    }
    free(numstr);
    return (i);

}

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

int printx(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int len = 0;
    len = ft_putnbr_base(num, "0123456789abcdef");
    return (len);
}

int printxx(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int len = 0;
    ft_putnbr_base(num, "0123456789ABCDEF");
    len = hex_len_ui(num);
    return (len);
}

int printsign (void)
{
    int c = '%';
    write(1, &c, 1);
    return (1);
}

int printp(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int len = hex_len(num) + 2;

    write(1, "x0", 2);
    put_hex(num);
    return(len);
}

int ft_printchar(const char c)
{
    write(1, &c, 1);
    return (1);
}

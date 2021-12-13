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

int ft_printchar (const char c)
{
    write(1, &c, 1);
    return (1);
}
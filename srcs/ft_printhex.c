/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:39:48 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/15 18:39:48 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int printx(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int len = 0;
    ft_putnbr_base(num, "0123456789abcdef");
    len = hex_len_ui(num);
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

int printp(va_list args)
{
    unsigned long long num = va_arg(args, unsigned long long);
    int len = hex_len(num) + 2;

    write(1, "x0", 2);
    put_hex(num);
    return(len);
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
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

int	printx(va_list args)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(args, unsigned int);
	ft_putnbr_base(num, "0123456789abcdef");
	if (num == 0)
		return (1);
	len = hex_len_ui(num);
	return (len);
}

int	printxx(va_list args)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(args, unsigned int);
	ft_putnbr_base(num, "0123456789ABCDEF");
	if (num == 0)
		return (1);
	len = hex_len_ui(num);
	return (len);
}

int	printp(va_list args)
{
	unsigned long long	num;
	int					len;

	num = va_arg(args, unsigned long long);
	len = hex_len(num) + 2;
	write(1, "0x", 2);
	put_hex(num);
	if (num == 0)
		return (3);
	return (len);
}

int	prints(va_list args)
{
	char	*s;
	int		i;

	s = va_arg(args, char *);
	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
	return (i);
}

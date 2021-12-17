/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:53:32 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/17 16:34:53 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ctoi(char c)
{
	int	i;

	i = c;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	int		(*f[256])(va_list args);
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	init_array(f);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				len += printsign();
			else
				len += (*f[ctoi(str[i + 1])])(args);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

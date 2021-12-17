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
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	printd(va_list args)
{
	char	*numstr;
	int		i;
	int		num;

	i = 0;
	num = va_arg(args, int);
	numstr = ft_itoa(num);
	while (numstr[i] != '\0')
	{
		write(1, &numstr[i], 1);
		i++;
	}
	free(numstr);
	return (i);
}

int	printu(va_list args)
{
	char			*numstr;
	int				i;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	i = 0;
	numstr = ft_utoa(num);
	while (numstr[i] != '\0')
	{
		write(1, &numstr[i], 1);
		i++;
	}
	free(numstr);
	return (i);
}

int	printc(va_list args)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	printsign(void)
{
	int	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}

int	ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:29:28 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/17 16:29:28 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_array(int (**f)(va_list args))
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

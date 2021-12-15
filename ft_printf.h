/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorrei <jocorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:08:05 by jocorrei          #+#    #+#             */
/*   Updated: 2021/12/13 18:08:05 by jocorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	init_array(int (**f)(va_list args));
int		printc(va_list args);
int		prints(va_list args);
int		printd(va_list args);
int		printu(va_list args);
int		printx(va_list args);
int		printxx(va_list args);
int		printsign(void);
int		printp(va_list args);
int		ft_printchar(const char c);

#endif
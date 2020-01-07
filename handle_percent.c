/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:56:21 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:56:24 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(char c, t_printf var, int *i)
{
	if (var.wdh >= 0)
		ft_width_trick(var.wdh - 1, ' ', i);
	ft_putchar(c, i);
	if (var.wdh < 0)
		ft_width_trick((var.wdh * -1) - 1, ' ', i);
}

void	handle_per(t_printf var, int *i)
{
	if (var.wdh >= 0)
		ft_width_trick(var.wdh - 1, ' ', i);
	if (var.zerowdh1 >= 0)
		ft_width_trick(var.zerowdh1 - 1, '0', i);
	ft_putchar(var.spcf, i);
	if (var.wdh < 0)
		ft_width_trick((var.wdh * -1) - 1, ' ', i);
	if (var.zerowdh1 < 0)
		ft_width_trick((var.zerowdh1 * -1) - 1, ' ', i);
}

void	handle_percent(const char **fmt, va_list argptr, int *i)
{
	t_printf	var;

	var = ft_getaftermod(fmt, argptr);
	if (var.spcf == 's')
		handle_string(va_arg(argptr, char *), var, i);
	else if (var.spcf == 'x' || var.spcf == 'X')
	{
		if (var.spcf == 'x')
			handle_x(va_arg(argptr, unsigned int), 0, var, i);
		else
			handle_x(va_arg(argptr, unsigned int), 1, var, i);
	}
	else if (var.spcf == 'd' || var.spcf == 'i')
		handle_int(va_arg(argptr, int), var, i);
	else if (var.spcf == 'c')
		handle_char(va_arg(argptr, int), var, i);
	else if (var.spcf == 'p')
		handle_p(va_arg(argptr, unsigned long), var, i);
	else if (var.spcf == 'u')
		handle_int(va_arg(argptr, unsigned int), var, i);
	else if (var.spcf == '%')
		handle_per(var, i);
	else
		handle_char(var.spcf, var, i);
}

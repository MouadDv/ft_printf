/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:54:34 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:55:10 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list argptr;
	int		printed_characters;

	va_start(argptr, fmt);
	printed_characters = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%' && *(fmt + 1) == '%')
		{
			ft_putchar('%', &printed_characters);
			fmt++;
		}
		else if (*fmt == '%' && *(fmt + 1) != '%')
			handle_percent(&fmt, argptr, &printed_characters);
		else
			ft_putchar(*fmt, &printed_characters);
		fmt++;
	}
	va_end(argptr);
	return (printed_characters);
}

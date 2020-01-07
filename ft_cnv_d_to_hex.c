/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnv_d_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:53:03 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:53:06 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(unsigned int nbr)
{
	int count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

void	ft_cnv_d_to_hex(unsigned int nbr, int *i, int flag)
{
	if (nbr > 0)
	{
		ft_cnv_d_to_hex(nbr / 16, i, flag);
		if (nbr % 16 > 9 && flag == 0)
			ft_putchar(nbr % 16 + 87, i);
		else if (nbr % 16 > 9 && flag == 1)
			ft_putchar(nbr % 16 + 55, i);
		else if (nbr % 16 <= 9)
			ft_putchar(nbr % 16 + 48, i);
	}
}

void	ft_cnv_d_to_hex_p(unsigned long nbr, int *i, int flag)
{
	if (nbr > 0)
	{
		ft_cnv_d_to_hex_p(nbr / 16, i, flag);
		if (nbr % 16 > 9 && flag == 0)
			ft_putchar(nbr % 16 + 87, i);
		else if (nbr % 16 > 9 && flag == 1)
			ft_putchar(nbr % 16 + 55, i);
		else if (nbr % 16 <= 9)
			ft_putchar(nbr % 16 + 48, i);
	}
}

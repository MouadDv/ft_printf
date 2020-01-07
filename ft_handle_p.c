/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:54:04 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:54:09 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_p_first(unsigned int nbr, t_printf *var, int *i)
{
	int lenstr;

	if (nbr == 0 && var->prc_wdh2 == 0)
		lenstr = 2;
	else if (nbr == 0)
		lenstr = 3;
	else
		lenstr = ft_hexlen(nbr) + 2;
	if (var->wdh > var->prc_wdh2 && var->prc_wdh2 >= lenstr)
		ft_width_trick(var->wdh - var->prc_wdh2, ' ', i);
	else if (var->wdh > var->prc_wdh2 && var->prc_wdh2 < lenstr)
		ft_width_trick(var->wdh - lenstr, ' ', i);
	if (var->zerowdh1 > 0 && var->prc_wdh2 >= lenstr)
		ft_width_trick(var->zerowdh1 - var->prc_wdh2, ' ', i);
	else if (var->zerowdh1 > 0 && var->prc_wdh2 < lenstr && var->prc_wdh2 >= 0)
		ft_width_trick(var->zerowdh1 - lenstr, ' ', i);
	if (var->prc_wdh2 >= 0)
		ft_width_trick(var->prc_wdh2 - lenstr, '0', i);
	if (var->zerowdh1 > 0 && var->prc_wdh2 < 0)
		ft_width_trick(var->zerowdh1 - lenstr, '0', i);
	return (lenstr);
}

void	handle_p(unsigned long nbr, t_printf var, int *i)
{
	int lenstr;

	lenstr = handle_p_first(nbr, &var, i);
	ft_putstr("0x", i);
	if (nbr == 0 && var.prc_wdh2 != 0)
		ft_putchar('0', i);
	ft_cnv_d_to_hex_p(nbr, i, 0);
	if (var.wdh < 0 && var.prc_wdh2 < (var.wdh * -1)
			&& lenstr >= var.prc_wdh2 && var.prc_wdh2 > 0)
		ft_width_trick((var.wdh * -1) - lenstr, ' ', i);
	else if (var.wdh < 0 && var.prc_wdh2 < (var.wdh * -1)
			&& lenstr < var.prc_wdh2 && var.prc_wdh2 > 0)
		ft_width_trick((var.wdh * -1) - var.prc_wdh2, ' ', i);
	else if (var.wdh < 0 && var.prc_wdh2 <= 0)
		ft_width_trick((var.wdh * -1) - lenstr, ' ', i);
	if (var.zerowdh1 < 0 && var.prc_wdh2 <= 0)
		ft_width_trick((var.zerowdh1 * -1) - lenstr, ' ', i);
}

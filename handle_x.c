/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:56:34 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:56:40 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_x_first(unsigned int nbr, t_printf *var, int *i)
{
	int lenstr;

	if (nbr == 0 && var->prc_wdh2 == 0)
		lenstr = 0;
	else if (nbr == 0)
		lenstr = 1;
	else
		lenstr = ft_hexlen(nbr);
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

void	handle_x(unsigned int nbr, int flag, t_printf var, int *i)
{
	int lenstr;

	lenstr = handle_x_first(nbr, &var, i);
	if (lenstr == 0 && var.prc_wdh2 >= 0)
		len_num(nbr);
	else if (nbr == 0)
		ft_putchar(nbr + 48, i);
	else
		ft_cnv_d_to_hex(nbr, i, flag);
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

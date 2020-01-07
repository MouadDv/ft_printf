/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:53:55 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:53:58 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_int_first(long *nbr, t_printf *var, int *n, int *i)
{
	int l;

	if (*nbr == 0 && var->prc_wdh2 > -1)
		l = 0;
	else
		l = len_num(*nbr);
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*n = 1;
	}
	if (var->wdh > var->prc_wdh2 && var->prc_wdh2 >= l && *n == 0)
		ft_width_trick(var->wdh - var->prc_wdh2, ' ', i);
	else if (var->wdh > var->prc_wdh2 && var->prc_wdh2 >= l && *n == 1)
		ft_width_trick(var->wdh - var->prc_wdh2 - *n, ' ', i);
	else if (var->wdh > var->prc_wdh2 && var->prc_wdh2 < l)
		ft_width_trick(var->wdh - l, ' ', i);
	if (var->zerowdh1 > 0 && var->prc_wdh2 >= l && *n == 0)
		ft_width_trick(var->zerowdh1 - var->prc_wdh2, ' ', i);
	else if (var->zerowdh1 > 0 && var->prc_wdh2 >= l && *n == 1)
		ft_width_trick(var->zerowdh1 - var->prc_wdh2 - *n, ' ', i);
	else if (var->zerowdh1 > 0 && var->prc_wdh2 < l && var->prc_wdh2 >= 0)
		ft_width_trick(var->zerowdh1 - l, ' ', i);
	return (l);
}

void	handle_int_min(int *lenstr, t_printf *var, int *n, int *i)
{
	if (var->zerowdh1 < 0 && var->prc_wdh2 > 0 && *n != 1
	&& *lenstr <= var->prc_wdh2)
		ft_width_trick((var->zerowdh1 * -1) - var->prc_wdh2, ' ', i);
	else if (var->wdh < 0 && var->prc_wdh2 < (var->wdh * -1)
	&& *lenstr >= var->prc_wdh2 && var->prc_wdh2 > 0)
	{
		if (*lenstr >= 3 && *n == 1 && var->prc_wdh2 >= *lenstr)
			*lenstr += 1;
		ft_width_trick((var->wdh * -1) - *lenstr, ' ', i);
	}
	else if (var->wdh < 0 && var->prc_wdh2 < (var->wdh * -1)
	&& *lenstr < var->prc_wdh2 && var->prc_wdh2 > 0)
		ft_width_trick((var->wdh * -1) - var->prc_wdh2 - *n, ' ', i);
	else if (var->wdh < 0 && var->prc_wdh2 <= 0)
		ft_width_trick((var->wdh * -1) - *lenstr, ' ', i);
	else if (var->zerowdh1 < 0 && var->prc_wdh2 <= 0)
		ft_width_trick((var->zerowdh1 * -1) - *lenstr, ' ', i);
}

void	handle_int(long nbr, t_printf var, int *i)
{
	int	lenstr;
	int	neg;

	neg = 0;
	lenstr = handle_int_first(&nbr, &var, &neg, i);
	if (neg == 1)
		ft_putchar('-', i);
	if (var.prc_wdh2 >= 0)
		ft_width_trick(var.prc_wdh2 - lenstr + neg, '0', i);
	if (var.zerowdh1 > 0 && var.prc_wdh2 < 0)
		ft_width_trick(var.zerowdh1 - lenstr, '0', i);
	if (lenstr == 0 && var.prc_wdh2 >= 0)
		len_num(nbr);
	else
		ft_putnbr(nbr, i);
	handle_int_min(&lenstr, &var, &neg, i);
}

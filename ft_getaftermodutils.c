/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermodutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:53:46 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:53:49 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	ft_clearstruct(void)
{
	t_printf var;

	var.wdh = 0;
	var.zerowdh1 = 0;
	var.prc_wdh2 = -1;
	var.flags = 0;
	var.spcf = 0;
	return (var);
}

void		ft_precision_width(const char **fmt, va_list argptr, t_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->prc_wdh2 = va_arg(argptr, int);
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->prc_wdh2 = ft_atoi(*fmt + 1);
	else
		ret->prc_wdh2 = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_zero_width(const char **fmt, va_list argptr, t_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->zerowdh1 = va_arg(argptr, int);
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->zerowdh1 = ft_atoi(*fmt);
	else
		ret->zerowdh1 = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_flag(const char **fmt, va_list argptr, t_printf *ret)
{
	if (*(*fmt + 1) == '*')
	{
		ret->wdh = va_arg(argptr, int);
		if (ret->wdh > 0)
			ret->wdh = ret->wdh * -1;
		*fmt = *fmt + 1;
	}
	else if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		ret->wdh = ft_atoi(*fmt);
	else
		ret->wdh = 0;
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

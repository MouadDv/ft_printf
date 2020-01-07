/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaftermod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:53:27 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:53:34 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wdh_num(const char **fmt, t_printf *ret)
{
	ret->wdh = ft_atoi(*fmt);
	while (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
		*fmt = *fmt + 1;
}

void		ft_zero_point(const char **fmt, t_printf *ret)
{
	ret->wdh = 0;
	ret->prc_wdh2 = 0;
	*fmt = *fmt + 1;
}

void		ft_getaftermodcond(const char **fmt, va_list argptr, t_printf *ret)
{
	while (**fmt != '\0')
	{
		if (**fmt == '*' && *(*fmt - 1) != '.')
			ret->wdh = va_arg(argptr, int);
		else if (**fmt == '*' && *(*fmt - 1) == '.')
			ret->prc_wdh2 = va_arg(argptr, int);
		else if (**fmt == '.')
			ft_precision_width(fmt, argptr, ret);
		else if (**fmt == '0' && *(*fmt + 1) == '.')
			ft_zero_point(fmt, ret);
		else if (**fmt == '0')
			ft_zero_width(fmt, argptr, ret);
		else if (**fmt == '-')
			ft_flag(fmt, argptr, ret);
		else if (**fmt >= '1' && **fmt <= '9')
			ft_wdh_num(fmt, ret);
		else if (ret->spcf == 0 && (**fmt < '1' || **fmt > '9'))
		{
			ret->spcf = **fmt;
			break ;
		}
		*fmt = *fmt + 1;
	}
}

t_printf	ft_getaftermod(const char **fmt, va_list argptr)
{
	t_printf ret;

	ret = ft_clearstruct();
	*fmt = *fmt + 1;
	ft_getaftermodcond(fmt, argptr, &ret);
	return (ret);
}

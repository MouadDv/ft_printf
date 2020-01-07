/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:56:28 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:56:30 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_specstr(char *str, int len, int *i)
{
	int	j;
	int	ret;

	j = 0;
	ret = 0;
	while (len > 0 && str[j] != '\0')
	{
		ft_putchar(str[j], i);
		ret = 1;
		len--;
		j++;
	}
	return (ret);
}

void	handle_string_b(char *str, t_printf *var, int *i)
{
	int lenstr;

	lenstr = ft_strlen(str);
	if (var->wdh < 0 && (var->prc_wdh2 >= lenstr || lenstr == 0))
		ft_width_trick((var->wdh * -1) - lenstr, ' ', i);
	else if ((var->wdh < 0 && var->prc_wdh2 < lenstr
				&& var->prc_wdh2 >= (var->wdh * -1)) || var->prc_wdh2 == -1)
		ft_width_trick((var->wdh * -1) - lenstr, ' ', i);
	else if ((var->wdh < 0 && var->prc_wdh2 < lenstr
				&& var->prc_wdh2 >= (var->wdh * -1)) || var->prc_wdh2 == 0)
		ft_width_trick((var->wdh * -1), ' ', i);
	else if (var->wdh < 0 && var->prc_wdh2 < (var->wdh * -1)
			&& var->prc_wdh2 < lenstr && var->prc_wdh2 < 0)
		ft_width_trick((var->wdh * -1) - lenstr, ' ', i);
	else if (var->wdh < 0 && var->prc_wdh2 < (var->wdh * -1)
			&& var->prc_wdh2 > 0)
		ft_width_trick((var->wdh * -1) - var->prc_wdh2, ' ', i);
}

void	handle_string(char *str, t_printf var, int *i)
{
	int lenstr;

	str = (str == NULL) ? "(null)" : str;
	lenstr = ft_strlen(str);
	if (var.wdh >= 0)
	{
		if (var.prc_wdh2 >= 0 && var.prc_wdh2 < lenstr && lenstr > 0)
			ft_width_trick(var.wdh - var.prc_wdh2, ' ', i);
		else
			ft_width_trick(var.wdh - lenstr, ' ', i);
	}
	if (var.prc_wdh2 >= 0)
		put_specstr(str, var.prc_wdh2, i);
	else
		ft_putstr(str, i);
	handle_string_b(str, &var, i);
}

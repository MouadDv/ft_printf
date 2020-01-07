/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:53:12 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:53:21 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_width(char *cmb)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (cmb[i] != '\0')
	{
		if (cmb[i] == '-' || (cmb[i] >= '0' && cmb[i] <= '9'))
			j++;
		if (j > 0 && cmb[i] != '-' && cmb[i] != '+'
				&& (cmb[i] < '0' || cmb[i] > '9'))
			break ;
		i++;
	}
	if (j > 0)
	{
		ret = malloc(j * sizeof(char) + 1);
		ret[j] = '\0';
		while (j-- >= 0)
			ret[j] = cmb[--i];
		return (ret);
	}
	return (NULL);
}

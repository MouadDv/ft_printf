/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:55:16 by milmi             #+#    #+#             */
/*   Updated: 2020/01/05 20:55:19 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct
{
	int		wdh;
	int		zerowdh1;
	int		prc_wdh2;
	int		spcf;
	int		flags;
}			t_printf;

int			ft_printf(const char *format, ...);
void		handle_percent(const char **format, va_list argptr, int *i);
void		ft_width_trick(int len, char c, int *i);
t_printf	ft_getaftermod(const char **format, va_list argptr);
void		ft_putstr(char *s, int *ptr);
void		ft_putchar(char c, int *i);
void		ft_putnbr(long nb, int *i);
size_t		ft_strlen(const char *str);
void		handle_modaftermod(char **ptr, int *i);
int			ft_atoi(const char *str);
int			len_num(long n);
void		ft_putunsigned(unsigned int nb, int *i);
t_printf	ft_clearstruct(void);
void		ft_precision_width(const char **fmt, va_list argptr, t_printf *ret);
void		ft_zero_width(const char **fmt, va_list argptr, t_printf *ret);
void		ft_flag(const char **fmt, va_list argptr, t_printf *ret);
void		handle_int(long nbr, t_printf var, int *i);
void		handle_string(char *str, t_printf var, int *i);
void		handle_x(unsigned int nbr, int flag, t_printf var, int *i);
void		handle_p(unsigned long nbr, t_printf var, int *i);
void		ft_cnv_d_to_hex(unsigned int nbr, int *i, int flag);
void		ft_cnv_d_to_hex_p(unsigned long nbr, int *i, int flag);
int			ft_hexlen(unsigned int nbr);
#endif

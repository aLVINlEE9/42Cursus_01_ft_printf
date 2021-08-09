/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_util_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:10:57 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 23:25:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign(int num, t_info *info_t)
{
	if (num >= 0)
		info_t->num_sign = 1;
	else
		info_t->num_sign = -1;
	return ;
}

void	ft_print_di_flag1(t_info *info_t, char *str)
{
	if (info_t->flag_1_space && info_t->num_sign == 1)
		ft_putchar(" ", info_t);
	else if (info_t->flag_1_plus && info_t->num_sign == 1)
		ft_putchar("+", info_t);
	else if (info_t->flag_1_hash && info_t->specifier == 'p')
		ft_putstr("0x", info_t, STR);
	else if (info_t->flag_1_hash && info_t->specifier == 'x' && \
			!(str[0] == '0'))
		ft_putstr("0x", info_t, STR);
	else if (info_t->flag_1_hash && info_t->specifier == 'X' && \
			!(str[0] == '0'))
		ft_putstr("0X", info_t, STR);
}

void	ft_width_print_di(t_info *info_t, char *str, char *stype)
{
	int	len;
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	if (info_t->num_sign == -1 || info_t->flag_1_plus == 1 || \
				info_t->flag_1_space == 1)
		sign += 1;
	else if (info_t->flag_1_hash == 1 || info_t->specifier == 'p')
		sign += 2;
	if (info_t->length <= (int)ft_strlen(str))
		len = (int)ft_strlen(str) + sign;
	else
		len = info_t->length + sign;
	if (info_t->width <= len)
		return ;
	else if (info_t->width > len)
	{
		while (i < info_t->width - len)
		{
			ft_putchar(stype, info_t);
			i++;
		}
	}
}

void	ft_length_print_di(t_info *info_t, char *str)
{
	int	i;

	i = 0;
	if (info_t->num_sign == -1)
		ft_putchar("-", info_t);
	if (info_t->length <= (int)ft_strlen(str))
	{
		ft_putstr(str, info_t, DI);
		return ;
	}
	else if (info_t->length > (int)ft_strlen(str))
	{
		while (i < info_t->length - (int)ft_strlen(str))
		{
			ft_putchar("0", info_t);
			i++;
		}
		ft_putstr(str, info_t, DI);
		return ;
	}
}

void	ft_print_di_flag2(t_info *info_t, char *str)
{
	if (info_t->flag_2_dash)
	{
		ft_print_di_flag1(info_t, str);
		ft_length_print_di(info_t, str);
		ft_width_print_di(info_t, str, " ");
	}
	else if (!info_t->flag_2_dash)
	{
		if (info_t->flag_2_zero && !info_t->precision)
		{
			if (info_t->num_sign == -1)
				ft_putchar("-", info_t);
			ft_print_di_flag1(info_t, str);
			ft_width_print_di(info_t, str, "0");
			ft_putstr(str, info_t, DI);
		}
		else
		{
			ft_width_print_di(info_t, str, " ");
			ft_print_di_flag1(info_t, str);
			ft_length_print_di(info_t, str);
		}
	}
}

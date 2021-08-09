/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:37:55 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/28 20:09:07 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags(t_info *info_t)
{
	info_t->idx += 1;
	return (1);
}

void	ft_get_flags(char *format, t_info *info_t)
{
	int	idx;

	idx = info_t->idx;
	while (format[idx] && format[idx] != info_t->specifier)
	{
		if (format[idx] == FLAG_1_HASH)
			info_t->flag_1_hash = ft_check_flags(info_t);
		else if (format[idx] == FLAG_1_SPACE)
			info_t->flag_1_space = ft_check_flags(info_t);
		else if (format[idx] == FLAG_1_PLUS)
			info_t->flag_1_plus = ft_check_flags(info_t);
		else if (format[idx] == FLAG_2_DASH)
			info_t->flag_2_dash = ft_check_flags(info_t);
		else if (format[idx] == FLAG_2_ZERO)
			info_t->flag_2_zero = ft_check_flags(info_t);
		else
			break ;
		idx++;
	}
}

int	ft_get_width_length(char *format, t_info *info_t)
{
	int	i;
	int	ret;

	i = info_t->idx;
	while (ft_isdigit(format[i]))
		i++;
	if (i == info_t->idx)
		return (0);
	ret = ft_atoi(&format[info_t->idx]);
	info_t->idx = i;
	return (ret);
}

void	ft_get_fixed_factor(char *format, t_info *info_t)
{
	ft_get_flags(format, info_t);
	info_t->width = ft_get_width_length(format, info_t);
	if (!info_t->precision)
		return ;
	info_t->idx++;
	info_t->length = ft_get_width_length(format, info_t);
}

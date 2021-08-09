/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variable_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:49:16 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 20:28:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_check_1(t_info *info_t, int type)
{
	if (type == CHAR && (!info_t->flag_1_hash && !info_t->flag_1_space \
				&& !info_t->flag_1_plus && !info_t->flag_2_zero && \
				!info_t->length))
		return (1);
	else if (type == STR && (!info_t->flag_1_hash && !info_t->flag_1_space \
				&& !info_t->flag_1_plus && !info_t->flag_2_zero))
		return (1);
	else if (type == DI && !info_t->flag_1_hash && !(info_t->flag_1_space && \
				info_t->flag_1_plus && !(info_t->flag_2_dash && \
				info_t->flag_2_zero)))
		return (1);
	else if (type == U && !info_t->flag_1_hash && !info_t->flag_1_space && \
				!info_t->flag_1_plus && !(info_t->flag_2_dash && \
				info_t->flag_2_zero))
		return (1);
	return (-1);
}

int	ft_print_check_2(t_info *info_t, int type)
{
	if (type == XX && !info_t->flag_1_space && !info_t->flag_1_plus && \
			!(info_t->flag_2_dash && info_t->flag_2_zero))
		return (1);
	else if (type == P && !info_t->flag_1_hash && !info_t->flag_1_space && \
			!info_t->flag_1_plus && !info_t->flag_2_zero && !info_t->length)
		return (1);
	else if (type == PERSENT && !info_t->flag_1_hash && !(info_t->flag_1_space \
				&& info_t->flag_1_plus))
		return (1);
	return (-1);
}

int	ft_which_specifier(va_list ap, t_info *info_t)
{
	char	type;

	type = info_t->specifier;
	if (type == 'c')
		return (ft_print_c(va_arg(ap, int), info_t));
	else if (type == 's')
		return (ft_print_s(va_arg(ap, char *), info_t));
	else if (type == 'd' || type == 'i' || type == 'u' || type == 'x' \
			|| type == 'X')
		return (ft_print_num(ap, info_t, type));
	else if (type == 'p')
		return (ft_print_num(ap, info_t, type));
	else if (type == '%')
		return (ft_print_persent(info_t));
	return (1);
}

int	ft_print_variable(va_list ap, t_info *info_t)
{
	return (ft_which_specifier(ap, info_t));
}

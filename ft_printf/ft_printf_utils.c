/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 09:49:28 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/29 17:40:37 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_t_info(t_info *info_t)
{
	info_t->width = 0;
	info_t->length = 0;
	info_t->flag_1_hash = 0;
	info_t->flag_1_space = 0;
	info_t->flag_1_plus = 0;
	info_t->flag_2_dash = 0;
	info_t->flag_2_zero = 0;
	info_t->precision = 0;
	info_t->pre_idx = 0;
	info_t->specifier = 0;
	info_t->num_sign = 0;
	info_t->num_type = 0;
}

int	ft_get_persent_idx(char *format, t_info *info_t)
{
	int	idx;

	info_t->idx += 1;
	idx = info_t->idx;
	if (!ft_strchr(&format[idx], '%'))
		return (0);
	return (ft_strchr(&format[idx], '%') - &format[idx] + 1);
}

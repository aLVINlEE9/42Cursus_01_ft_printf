/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:57:33 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 23:23:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero_handling(char *str, int num, t_info *info_t)
{
	if (num == 0 && info_t->length == 0 && info_t->precision == 1)
	{
		str[0] = ' ';
		str[1] = '\0';
		if (info_t->width == 0)
			str[0] = '\0';
	}
	return (str);
}

int	ft_print_d_i(int num, t_info *info_t)
{
	char	*str;

	if (ft_print_check_1(info_t, DI) == -1)
		return (-1);
	info_t->num_type = 10;
	ft_check_sign(num, info_t);
	str = ft_itoa((int)num, info_t);
	str = ft_zero_handling(str, num, info_t);
	ft_print_di_flag2(info_t, str);
	free(str);
	return (1);
}

int	ft_print_ux(unsigned long long num, t_info *info_t, char type)
{
	char	*str;

	if (type == 'u')
	{
		info_t->num_type = 10;
		if (ft_print_check_1(info_t, U) == -1)
			return (-1);
	}
	else if (type == 'x' || type == 'X')
	{
		info_t->num_type = 16;
		if (ft_print_check_2(info_t, XX) == -1)
			return (-1);
	}
	str = ft_itoa_un(num, info_t, type);
	str = ft_zero_handling(str, num, info_t);
	ft_print_di_flag2(info_t, str);
	free(str);
	return (1);
}

int	ft_print_p(unsigned long long num, t_info *info_t)
{
	char	*str;

	info_t->num_type = 16;
	if (ft_print_check_2(info_t, P) == -1)
		return (-1);
	info_t->flag_1_hash = 1;
	str = ft_itoa_un(num, info_t, 'p');
	ft_print_di_flag2(info_t, str);
	free(str);
	return (1);
}

int	ft_print_num(va_list ap, t_info *info_t, char type)
{
	if (type == 'd' || type == 'i')
		return (ft_print_d_i(va_arg(ap, int), info_t));
	else if (type == 'u' || type == 'x' || type == 'X')
		return (ft_print_ux(va_arg(ap, unsigned int), info_t, type));
	else if (type == 'p')
		return (ft_print_p(va_arg(ap, unsigned long long), info_t));
	return (1);
}

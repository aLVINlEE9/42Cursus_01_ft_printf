/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:20:34 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 19:07:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_specifier(char *format, t_info *info_t, char *specifiers)
{
	int	i;
	int	j;

	j = ++info_t->idx;
	while (format[j] && !info_t->specifier)
	{
		i = 0;
		while (specifiers[i])
		{
			if (ft_strchr_size(&format[j], specifiers[i], 1))
			{
				info_t->specifier = ft_strchr_size(&format[j], \
					specifiers[i], 1)[0];
				if (info_t->specifier)
					break ;
			}
			i++;
		}
		j++;
	}
}

void	ft_get_precision(char *format, t_info *info_t, char flags)
{
	int		i;
	char	dot;

	dot = '\0';
	i = info_t->idx;
	while (!info_t->precision)
	{
		if (ft_strchr_size(&format[i], flags, 1))
		{
			info_t->precision = 1;
			info_t->pre_idx = i;
		}
		if (ft_strchr_size(&format[i], info_t->specifier, 1))
			break ;
		i++;
	}
	return ;
}

void	ft_set_t_info(char *format, t_info *info_t)
{
	ft_init_t_info(info_t);
	ft_get_specifier(format, info_t, SPECIFIER);
	ft_get_precision(format, info_t, PRECISION);
	ft_get_fixed_factor(format, info_t);
	return ;
}

int	ft_parsing(va_list ap, char *format)
{
	t_info	*info_t;
	int		error;
	int		ret;

	error = 0;
	info_t = malloc(sizeof(t_info));
	info_t->idx = 0;
	info_t->ret_idx = 0;
	while (format[info_t->idx])
	{
		if (format[info_t->idx] == '%')
		{
			ft_set_t_info(format, info_t);
			error = ft_print_variable(ap, info_t);
			if (error == -1)
				return (-1);
		}
		else
			ft_putchar(&format[info_t->idx], info_t);
		info_t->idx++;
	}
	ret = info_t->ret_idx;
	free(info_t);
	return (ret);
}

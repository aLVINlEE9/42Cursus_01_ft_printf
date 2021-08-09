/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:32:38 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 22:50:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_print_char(t_info *info_t, int len, int type)
{
	int	width;
	int	length;

	if (type == CHAR)
	{
		width = info_t->width;
		if (width == 0)
			return ;
		width -= 1;
		while (width--)
			ft_putchar(" ", info_t);
	}
	else if (type == STR)
	{
		length = info_t->length;
		width = info_t->width;
		if (len > length && info_t->precision)
			len = length;
		if (width == 0 || width < len)
			return ;
		width -= (len);
		while (width--)
			ft_putchar(" ", info_t);
	}
}

void	ft_length_print_char(t_info *info_t, char *s, int type)
{
	int	length;
	int	idx;

	length = info_t->length;
	if (type == CHAR)
	{
		ft_putstr(s, info_t, CHAR);
		return ;
	}
	if (!info_t->precision)
	{
		ft_putstr(s, info_t, type);
		return ;
	}
	idx = 0;
	while (s[idx] && idx < length)
		ft_putchar(&s[idx++], info_t);
}

int	ft_print_c_str(t_info *info_t, char *s, int type)
{
	int	len;

	len = ft_strlen(s);
	if (info_t->flag_2_dash)
	{
		ft_length_print_char(info_t, s, type);
		ft_width_print_char(info_t, len, type);
		return (1);
	}
	else
	{
		ft_width_print_char(info_t, len, type);
		ft_length_print_char(info_t, s, type);
		return (1);
	}
	return (1);
}

int	ft_print_c(int i, t_info *info_t)
{
	char	c;

	if (ft_print_check_1(info_t, CHAR) == -1)
		return (-1);
	c = (char)i;
	ft_print_c_str(info_t, &c, CHAR);
	return (1);
}

int	ft_print_s(char *str, t_info *info_t)
{
	if (ft_print_check_1(info_t, STR) == -1)
		return (-1);
	if (str == NULL)
		str = "(null)";
	ft_print_c_str(info_t, str, STR);
	return (1);
}

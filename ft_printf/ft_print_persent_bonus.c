/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_persent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 22:25:08 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/29 15:38:32 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_print_prs(t_info *info_t)
{
	char	*stype;
	int		width;
	int		i;

	i = 0;
	width = info_t->width;
	if (info_t->flag_2_dash)
	{
		ft_putchar("%", info_t);
		while (++i < width)
			ft_putchar(" ", info_t);
	}
	else if (!info_t->flag_2_dash)
	{
		stype = " ";
		if (info_t->flag_2_zero)
			stype = "0";
		while (++i < width)
			ft_putchar(stype, info_t);
		ft_putchar("%", info_t);
	}
}

int	ft_print_persent(t_info *info_t)
{
	if (ft_print_check_2(info_t, PERSENT) == -1)
		return (-1);
	ft_width_print_prs(info_t);
	return (1);
}

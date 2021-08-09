/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:26:26 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/28 20:25:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_info *info_t, int c)
{
	int	i;

	if (c == CHAR)
	{
		ft_putchar(s, info_t);
		return ;
	}
	else if (c == STR || c == DI)
	{
		i = 0;
		if (!s)
			return ;
		while (s[i])
			ft_putchar(&s[i++], info_t);
		return ;
	}
	return ;
}

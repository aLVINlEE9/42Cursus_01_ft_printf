/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:28:57 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/27 13:11:08 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_size(const char *s, int c, int len)
{
	if (len == 0)
		return (ft_strchr(s, c));
	return (ft_memchr(s, c, len));
}

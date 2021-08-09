/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:25:10 by seungsle          #+#    #+#             */
/*   Updated: 2021/07/23 13:31:32 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_u;

	i = 0;
	s_u = (unsigned char *)s;
	while (i < n)
	{
		if (s_u[i] == (unsigned char)c)
		{
			return ((void *)(s_u + i));
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:16:39 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 23:26:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_size_un(unsigned long long n, t_info *info_t)
{
	size_t	i;

	i = 0;
	while (1)
	{
		i++;
		n /= info_t->num_type;
		if (n == 0)
			break ;
	}
	return (i);
}

char	*ft_put_s_un(char *r, unsigned long long n, t_info *in_t, char t)
{
	int	idx;
	int	s;

	s = ft_num_size_un(n, in_t);
	idx = s - 1;
	r[s] = '\0';
	while (1)
	{
		if (n % in_t->num_type < 10)
			r[idx] = '0' + (n % in_t->num_type);
		else if (n % in_t->num_type >= 10)
		{
			if (t == 'X')
				r[idx] = 'A' + (n % in_t->num_type - 10);
			else
				r[idx] = 'a' + (n % in_t->num_type - 10);
		}
		n /= in_t->num_type;
		idx--;
		if (n == 0)
			break ;
	}
	return (r);
}

char	*ft_itoa_un(unsigned long long n, t_info *info_t, char type)
{
	int		size;
	char	*ret;

	size = ft_num_size_un(n, info_t);
	ret = ft_malloc(size);
	if (!ret)
		return (NULL);
	ret = ft_put_s_un(ret, n, info_t, type);
	return (ret);
}

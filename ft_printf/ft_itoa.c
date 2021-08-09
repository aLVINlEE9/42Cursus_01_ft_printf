/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:16:39 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 17:53:02 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_size(long n, t_info *info_t)
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

char	*ft_malloc(size_t size)
{
	char		*ret;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	return (ret);
}

char	*ft_put_str(char *ret, long num, int size, t_info *info_t)
{
	int	idx;

	idx = size - 1;
	ret[size] = '\0';
	while (1)
	{
		if (num % info_t->num_type < 10)
			ret[idx] = '0' + (num % info_t->num_type);
		else if (num % info_t->num_type >= 10)
			ret[idx] = 'A' + (num % info_t->num_type - 10);
		num /= info_t->num_type;
		idx--;
		if (num == 0)
			break ;
	}
	return (ret);
}

char	*ft_itoa(long n, t_info *info_t)
{
	int		size;
	char	*ret;

	if (info_t->num_sign == -1)
		n *= -1;
	size = ft_num_size(n, info_t);
	ret = ft_malloc(size);
	if (!ret)
		return (NULL);
	ret = ft_put_str(ret, n, size, info_t);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:52:11 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 22:55:08 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	ret;

	va_list(ap);
	va_start(ap, format);
	ret = ft_parsing(ap, (char *)format);
	va_end(ap);
	return (ret);
}

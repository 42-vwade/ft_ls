/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:40:04 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 01:13:51 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Complete rewrite incoming.
*/

int
	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		length[1];

	va_start(ap, format);
	length[0] = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (length[0]);
}

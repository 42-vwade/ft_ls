/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_sprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:40:04 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 01:08:58 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Complete rewrite incoming.
*/

int
	ft_std_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		length[1];

	va_start(ap, format);
	length[0] = ft_std_vsprintf(str, format, ap);
	va_end(ap);
	return (length[0]);
}

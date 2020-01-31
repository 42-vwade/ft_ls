/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:40:04 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 01:10:49 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Complete rewrite incoming.
*/

caddr_t
	ft_sprintf(const char *format, ...)
{
	va_list	ap;
	caddr_t	str;

	va_start(ap, format);
	str = ft_vsprintf(format, ap);
	va_end(ap);
	return (str);
}

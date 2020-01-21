/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:35 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 11:55:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_specifier(t_format *o, const char *format)
{
	size_t	n;

	n = 1;
	if (!format[0])
		RET(0);
	while (format[n] && !(o->f = o->jump[ft_tolower(format[n])]))
		++n;
	(o->f) && (o->str = (char*)&format[n]);
	RET(o->f ? n : 0);
}

/*
**	MATCH(!format[0], ft_error("invalid syntax"));
*/

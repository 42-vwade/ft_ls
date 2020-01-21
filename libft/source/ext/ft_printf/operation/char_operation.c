/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 16:03:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		CHAR
*/

static void
	width_c(t_format *o)
{
	o->v = encode_output(0, o->v);
	if (!o->p.width || !(o->p.width -= !!o->v))
		RET;
	o->pad = encode_output(0, ft_memset(
		ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width));
}

static FT_SIZE
	convert_c(t_format *o)
{
	((o->str[0] == '%') && (*(uint64_t*)o->v = '%'));
	((o->p.length == l) && (o->v = encode_utf8((int[2]){*(int64_t *)o->v, 0})))
	|| (o->v = ft_strdup((char[2]){*(char *)o->v, 0}));
	width_c(o);
	append_s(o);
	return (1);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t is retrieved.
**	An uppercase specifier (C) is treated as if the length flag was given.
**	Otherwise, a null-terminated char is retrieved.
*/

int
	parse_c(t_format *o)
{
	uint64_t	c;

	o->v = &c;
	((ft_isuppercase(o->str[0]) || o->p.length > 8) && (o->p.length = l));
	if (!(o->str[0] == 'r' && ((c = *(uint64_t*)o->tmp) || 1)) || o->str[0] != '%')
		cast_o(o);
	return (convert_c(o));
}

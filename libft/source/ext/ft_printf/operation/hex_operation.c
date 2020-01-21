/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 11:40:47 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static FT_SIZE
	convert_x(t_format *o)
{
	char	u;

	u = ft_tolower(o->str[0]);
	((u == 'b') && ((u = 2) || 1))
	|| (u = 16 >> (u == 'o'));
	((o->p.tick & 4 && !o->p.precision && !*(int64_t*)o->v)
	&& ((o->v = 0) || 1))
	|| (o->v = ft_itoa_base(*(uint64_t*)o->v, u));
	precision_i(o);
	width_o(o);
	append_s(o);
	return (1);
}

/*
**	Conditions already taken care of.
**	Input specifier shall be o / O / x / X / p / P
**	Output shall be in in either base 16, or base 8 if o / O is given
*/

int
	parse_x(t_format *o)
{
	uint64_t	num;

	o->v = &num;
	(o->p.length > 8) && (o->p.length = l);
	(o->p.tick & (1 << 6) && !o->p.precision) && ((o->p.tick &= ~(1 << 2)));
	(ft_tolower(o->str[0]) == 'p') && (o->p.length = l);
	(ft_tolower(o->str[0]) == 'p') && (o->p.flags |= hash);
	(o->p.tick & 4) && (o->p.flags &= ~zero);
	cast_o(o);
	return (convert_x(o));
}

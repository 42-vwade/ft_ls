/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:41:33 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 14:21:40 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	width_o(t_format *o)
{
	uint64_t	zpad;

	zpad = ft_strlen(o->v) + !!o->sign + ft_strlen(o->z_pad);
	hash_o(o);
	zpad += ft_strlen(o->prefix);
	o->p.width = MAX((LL)(o->p.width - zpad), 0);
	if (!o->p.width)
		RET;
	o->pad =
	ft_memset(ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width);
	return ;
	if (o->p.flags & zero &&
		!((o->p.tick & 4) && ft_strchr("dioux", ft_tolower(*o->str))) &&
		((((ft_strchr("xp", ft_tolower(o->str[0]))) &&
		(o->v = search_and_splice(o->v, "0x", o->pad))) ||
		(o->v = ft_append(o->pad, o->v, 3))) || 1))
		return ;
	else
		ft_memset(o->pad, ' ', o->p.width);
	((minus & o->p.flags) && (o->v = ft_append(o->v, o->pad, 3))) ||
	(o->v = ft_append(o->pad, o->v, 3));
	(ft_isuppercase(o->str[0])) && (ft_strcapitalize(o->v));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:36 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 16:00:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define _P	prefix
#define _Z	z_pad
#define _A	ft_append
#define _C	ft_strcapitalize

void
	append_s(t_format *o)
{
	char	left;
	char	zer0;

	left = o->p.flags & minus;
	zer0 = o->p.flags & zero;
	((o->_P && o->_Z) && ((o->_Z = _A(o->_P, o->_Z, 2)) || 1))
	|| ((o->_P && o->pad && zer0) && ((o->pad = _A(o->_P, o->pad, 2)) || 1))
	|| ((o->_P) && (o->v = _A(o->_P, o->v, 2)));
	((o->sign && o->_Z) && ((o->_Z = _A(o->sign, o->_Z, 2)) || 1))
	|| ((o->sign && o->pad && zer0) && ((o->pad = _A(o->sign, o->pad, 2)) || 1))
	|| ((o->sign) && (o->v = _A(o->sign, o->v, 2)));
	((o->_Z) && (o->v = _A(o->_Z, o->v, 3)));
	((left) && ((o->v = _A(o->v, o->pad, 3)) || 1))
	|| ((o->pad) && (o->v = _A(o->pad, o->v, 3)));
	(o->v && ANY2(o->str[0], 'X', 'P')) && (_C(o->v));
}

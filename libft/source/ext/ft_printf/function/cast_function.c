/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 06:10:12 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 15:58:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	set_size(uint64_t *v, uint64_t len, va_list ap)
{
	((len == 0) && ((v[0] = (unsigned char)va_arg(ap, uint)) || 1))
	|| ((len == 1) && ((v[0] = (unsigned char)va_arg(ap, uint)) || 1))
	|| ((len == 2) && ((v[0] = (unsigned short)va_arg(ap, uint)) || 1))
	|| ((len == 4) && ((v[0] = (unsigned int)va_arg(ap, uint)) || 1))
	|| ((len == 8) && ((v[0] = (unsigned long long)va_arg(ap, int64_t)) || 1))
	|| ((len > 8) && (v[0] = (long double)va_arg(ap, double_t)));
}

void
	cast_o(t_format *o)
{
	return (set_size(o->v, o->p.length, o->ap));
}

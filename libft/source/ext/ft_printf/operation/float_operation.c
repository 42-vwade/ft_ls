/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 16:02:23 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static FT_SIZE
	convert_f(t_format *o)
{
	width_o(o);
	append_s(o);
	return (3);
}

static int
	is_float(t_format *o)
{
	((!(o->p.tick & 0b100))
	&& (o->p.precision = 6));
	((o->p.length > 8)
	&& ((o->v = infinite_double(*(long double*)o->v, o->p.precision)) || 1))
	|| (o->v = infinite_double((long double)*(double*)o->v, o->p.precision));
	return (0);
}

static int
	is_anomaly(long double num, t_format *o)
{
	FT_NBR	n;

	n.d = NULL;
	if ((n.length = (num != num) * 3))
		n.d = ft_strdup("nan");
	else if ((n.length = (num == INFINITY) * 3))
		n.d = ft_strdup("inf");
	else if ((n.length = (num == -INFINITY) * 4))
		n.d = ft_strdup("-inf");
	return (n.d && (o->v = n.d));
	return (n.length);
}

int
	parse_f(t_format *o)
{
	size_t		ret;
	double		num;
	long double	ld;

	ret = 0;
	((o->p.length <= 8) && (o->v = &num))
	|| (o->v = &ld);
	((o->p.length <= 8) && ((num = va_arg(o->ap, double)) || 1))
	|| (ld = va_arg(o->ap, long double));
	o->p.flags |= (num < 0) << 7;
	((o->p.length > 8) && ((ret = is_anomaly(*(long double*)o->v, o)) || 1))
	|| (ret = is_anomaly((long double)*(double*)o->v, o));
	if (ret || is_float(o))
		RET(ret);
	return (convert_f(o));
}

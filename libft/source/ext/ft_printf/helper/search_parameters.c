/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:49:18 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 12:20:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define _TL ft_tolower

static void
	search_flags(uint64_t *set, const char *f, size_t *len, size_t *i)
{
	set[0] = 0;
	while (*i < *len || (*i = 0))
	{
		if (('1' <= f[*i] && f[*i] <= '9') || f[*i] == '.')
			break ;
		((f[*i] == '+') && ((set[0] = (set[0] | plus) & ~space) || 1))
		|| ((f[*i] == '-') && ((set[0] = (set[0] | minus) & ~zero) || 1))
		|| ((f[*i] == '0') && ((set[0] |= !(minus & set[0]) << 2) || 1))
		|| ((f[*i] == '#') && ((set[0] |= hash) || 1))
		|| ((f[*i] == ' ') && ((set[0] |= !(plus & set[0]) << 4) || 1));
		*i = *i + 1;
		if (*i == *len && !(*i = 0))
			RET;
	}
	while (*i < *len && (('0' <= f[*i] && f[*i] <= '9') || f[*i] == '.'))
		*i = *i + 1;
	while (*i < *len || (*i = 0))
	{
		((f[*i] == '+') && ((set[0] = (set[0] | plus) & ~(space)) || 1))
		|| ((f[*i] == '-') && ((set[0] = (set[0] | minus) & ~(zero)) || 1))
		|| ((f[*i] == '0') && ((set[0] |= !(minus & set[0]) << 2) || 1))
		|| ((f[*i] == '#') && ((set[0] |= 1 << 3) || 1))
		|| ((f[*i] == ' ') && ((set[0] |= !(plus & set[0]) << 4) || 1))
		|| ((*i = *i + 1));
	}
}

static int
	search_width(t_format *o, uint64_t *w, const char *f, size_t *i)
{
	w[0] = 0;
	while (*i < o->len && f[*i] != '.' && f[*i] != '*' &&
			!('1' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	((f[*i] == '*')
	&& ((*i += 1) && (w[0] = va_arg(o->ap, int))));
	((w[0] >= (unsigned long)0x80 << ((sizeof(w[0]) - 1) * 8))
	&& ((o->p.flags = minus)
	&& (w[0] = ~(w[0] - 1))));
	if (ft_isdigit(f[*i]) && ((w[0] = ft_atoi(&f[*i])) && 0))
		RET(0);
	while (*i < o->len && ('0' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	RET(0);
}

static int
	search_precision(t_format *o, uint64_t *p, const char *f, size_t *i)
{
	p[0] = 0;
	while (*i < o->len && f[*i] != '.')
		*i += 1;
	if (!((f[*i] == '.') && (((o->p.tick |= 1 << 2) && (*i += 1)) || 1)))
		RET(0);
	(f[*i] == '*') && ((p[0] = va_arg(o->ap, int)));
	((p[0] >= (unsigned long)0x80 << ((sizeof(p[0]) - 1) * 8)) && ((!(p[0] = 0)
	&& (o->p.tick &= ~(1 << 2))) || 1))
	|| ((f[*i] == '*') && (o->p.tick |= 1 << 6));
	(f[*i] == '*') && ((*i += 1));
	if (('0' <= f[*i] && f[*i] <= '9') && ((p[0] = ft_atoi(&f[*i])) && 0))
		RET(0);
	while (*i < o->len && ('0' <= f[*i] && f[*i] <= '9'))
		*i = *i + 1;
	RET(0);
}

static void
	search_length(uint64_t *set, const char *f, size_t *len, size_t *i)
{
	i[0] = 0;
	set[0] = sizeof(int);
	while (*i < *len && !ft_strchr("hlLjzt", f[*i]))
		*i = *i + 1;
	((f[*i] == 'h') && ((set[0] = (f[*i + 1] == 'h') ? hh : h) || 1))
	|| ((f[*i] == 'L') && ((set[0] = LD) || 1))
	|| ((f[*i] == 'l') && ((set[0] = (_TL(f[*i + 1]) == 'l') ? ll : l) || 1))
	|| ((f[*i] == 'j') && ((set[0] = j) || 1))
	|| ((f[*i] == 'z') && ((set[0] = z) || 1));
	(set[0] != 4) && (*i += 1 + (set[0] & (ll + hh)));
}

void
	search_parameters(t_format *o, const char *format)
{
	o->p = (t_param){0, 0, 0, 0, 4};
	if (o->len == 0)
		return ;
	search_flags(&o->p.flags, format, &o->len, &(size_t){0});
	search_width(o, &o->p.width, format, &(size_t){0});
	o->p.tick = !!o->p.flags << 0;
	o->p.tick |= !!o->p.width << 1;
	search_precision(o, &o->p.precision, format, &(size_t){0});
	search_length(&o->p.length, format, &o->len, &(size_t){0});
	o->p.tick |= (o->p.length != 4) << 3;
}

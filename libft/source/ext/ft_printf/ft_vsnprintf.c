/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:34:16 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 01:05:00 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static void
	format_convert(t_format *o, const char *format, size_t *i)
{
	++i[0];
	o->pad = 0;
	o->sign = 0;
	o->z_pad = 0;
	o->prefix = 0;
	o->p.length = 4;
	if (!(o->len = find_specifier(o, format)))
		return ;
	i[0] += o->len--;
	search_parameters(o, &format[1]);
	o->f(o);
	(ft_strchr("%c", ft_tolower(*o->str))
	&& ((o->encode = ft_append(o->encode, o->v, 3)) || 1))
	|| (o->encode = encode_output(o->encode, o->v));
}

static size_t
	find_next(const char *s)
{
	const char *e;

	e = s;
	while (e[0] && e[0] != '%')
		e++;
	return (e - s);
}

static void
	create_string(t_format *o, const char *format)
{
	size_t	i;
	size_t	tonext;

	i = 0;
	while (format[i])
	{
		tonext = find_next(&format[i]);
		if (tonext &&
		!(o->encode = encode_output(o->encode, ft_strsub(format, i, tonext))))
			ft_error("ft_printf: failed to append text to output");
		i += tonext;
		if (format[i] && format[i] == '%')
			format_convert(o, &format[i], &i);
		(o->color && !format[i])
		&& (o->encode = encode_output(o->encode, ft_strdup("\x1b[0m")));
	}
	(o->encode) && (o->output = decode_output(o->encode, &o->write));
}

static void
	init_format(t_format *o, va_list ap, const char *format)
{
	ft_bzero(o, sizeof(*o));
	va_copy(o->ap, ap);
	o->format = format;
	o->jump['%'] = parse_c;
	o->jump['c'] = parse_c;
	o->jump['s'] = parse_s;
	o->jump['p'] = parse_x;
	o->jump['d'] = parse_i;
	o->jump['i'] = parse_i;
	o->jump['u'] = parse_i;
	o->jump['o'] = parse_x;
	o->jump['x'] = parse_x;
	o->jump['f'] = parse_f;
	o->jump['e'] = 0;
	o->jump['g'] = 0;
	o->jump['a'] = parse_a;
	o->jump['n'] = 0;
	o->jump['b'] = parse_x;
}

int
	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_format	o;

	init_format(&o, ap, format);
	create_string(&o, format);
	ft_strncpy(str, o.output, size);
	ft_memdel(&o.output);
	va_end(o.ap);
	return (o.write);
}

/*
**	int
**		ft_vprintf(const char *format, va_list ap)
**	{
**		t_format	o;
**
**		ft_bzero(&o, sizeof(o));
**		va_copy(o.ap, ap);
**		parse_input(&o, o.str = (char *)format);
**		va_end(o.ap);
**		return (o.count);
**	}
*/

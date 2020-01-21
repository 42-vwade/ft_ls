/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:57:50 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 16:53:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define C_RESET		0
#define C_BLACK		1
#define C_RED		2
#define C_GREEN		3
#define C_YELLOW	4
#define C_BLUE		5
#define C_MAGENTA	6
#define C_CYAN		7
#define C_WHITE		8
#define C_B_BLACK	9
#define C_B_RED		10
#define C_B_GREEN	11
#define C_B_YELLOW	12
#define C_B_BLUE	13
#define C_B_MAGENTA	14
#define C_B_CYAN	15
#define C_B_WHITE	16
#define _AA	ft_append
#define _I	ft_itoa

static uint8_t
	get_color(char *s)
{
	uint8_t	col;

	col = C_BLACK;
	(ft_strequ("white", s) && ((col = C_WHITE) || 1))
	|| (ft_strequ("magenta", s) && ((col = C_MAGENTA) || 1))
	|| (ft_strequ("cyan", s) && ((col = C_CYAN) || 1))
	|| (ft_strequ("yellow", s) && ((col = C_YELLOW) || 1))
	|| (ft_strequ("blue", s) && ((col = C_BLUE) || 1))
	|| (ft_strequ("green", s) && ((col = C_GREEN) || 1))
	|| (ft_strequ("red", s) && (col = C_RED));
	return (col);
}

static int
	convert_a(t_format *o)
{
	char	n;
	char	**m;

	m = (char *[]){"\x1b[3", "\x1b[38;5;", "m", ";1m"};
	n = *(char *)o->v;
	((!o->v) && ((o->v = _AA(m[0], "0", 0)) || 1));
	((n < 8) && ((o->v = _AA(m[0], _AA(_I(n), m[2], 1), 2)) || 1))
	|| ((n < 16) && ((o->v = _AA(m[0], _AA(_I(n - 8), m[3], 1), 2)) || 1))
	|| ((n >= 16) && ((o->v = _AA(m[1], _AA(_I(n), m[2], 1), 2)) || 1));
	append_s(o);
	return (0);
}

static uint64_t
	synthesize_color(char *s)
{
	char		bright;
	char		*tmp;
	uint64_t	col;

	if (!s)
		RET(0);
	col = 0;
	bright = 0;
	if (!(s = ft_strtrim(s)))
		ft_error("synth_col (error) : trim 1");
	ft_strtolower(&s);
	tmp = s;
	if ((bright = 8 * ft_strnequ("bright", s, 6)))
		((((s += 6) || 1) && (s = ft_strtrim(s))) || 1);
	if (bright)
		ft_memdel((void**)&tmp);
	if (!(col = get_color(s) + bright))
		((s[0] && s[1]) && (col = (unsigned char)ft_atoi(s)));
	return (col);
}

int	parse_a(t_format *o)
{
	uint64_t	color;

	color = 0;
	((!o->color) && (o->color = 1));
	o->v = &color;
	((o->p.flags & hash) && ((o->v = va_arg(o->ap, void *)) || 1))
	|| (color = (unsigned char)va_arg(o->ap, int));
	if (!o->v && !color)
		RET(convert_a(o));
	(o->v != &color) && (((color = synthesize_color(o->v)) || 1));
	((o->v != &color) && (((color -= 1) || 1)
		&& (o->v = &color)));
	return (convert_a(o));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 15:49:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**		INT
*/

/*
**		Zero Pad Integer.
**	#.	If [precision] given && if [precision] > [value].length
**			Set total [precision] = [precision] - [value].length, max 0
**		[zero] prepend number with [precision] # of '0' characters
**		<Character> Pad String.
*/

static int
	convert_i(t_format *o)
{
	((o->p.tick & 4 && !o->p.precision && !*(int64_t*)o->v)
	&& ((o->v = 0) || 1))
	|| ((o->p.flags & neg) && ((o->v = ft_itoa(*(int64_t*)o->v)) || 1))
	|| (o->v = ft_itoa_unsigned(*(uint64_t*)o->v));
	precision_i(o);
	width_o(o);
	append_s(o);
	return (o->len);
}

/*
**	1.	64-bit signed placeholder variable. Signage enables negative check.
**	3.	Assign address of placeholder to object. For later modification.
**	4.	Get appropriate value based on length specifier.
**	5.	Check if value is unsigned && value is negative.
**		Positive integer values do not matter.
**	6.	Send object to conversion task. Return number of characters written.
*/

int
	parse_i(t_format *o)
{
	char		c;
	uint64_t	num;

	o->v = &num;
	c = ft_tolower(o->str[0]);
	((o->p.length > 8) && (o->p.length = l));
	((o->p.tick & (1 << 6) && !o->p.precision) && ((o->p.tick &= ~(1 << 2))));
	((o->p.tick & 4) && (o->p.flags &= ~zero));
	cast_o(o);
	((c != 'u' && num >= (uint64_t)0x80 << (o->p.length - 1) * 8)
	&& (o->p.flags = (o->p.flags & ~(plus + space)) | neg));
	((neg & o->p.flags) && (num = ~(num - 1) & ~0UL >> (64 - o->p.length * 8)));
	return (convert_i(o));
}

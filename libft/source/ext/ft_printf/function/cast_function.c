/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 06:10:12 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 14:16:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SIZE_0(v)	v=(unsigned char)va_arg(o->ap, uint)
#define SIZE_1(v)	v=(unsigned char)va_arg(o->ap, uint)
#define SIZE_2(v)	v=(unsigned short)va_arg(o->ap, uint)
#define SIZE_3(v)	v=(unsigned int)va_arg(o->ap, uint)
#define SIZE_4(v)	v=(unsigned long long)va_arg(o->ap, int64_t)
#define SIZE_5(v)	v=(long double)va_arg(o->ap, double_t)

void
	cast_o(t_format *o)
{
	MATCH(o->p.length == 0, SIZE_0(*((uint64_t *)o->v)));
	OR(o->p.length == 1, SIZE_1(*((uint64_t *)o->v)));
	OR(o->p.length == 2, SIZE_2(*((uint64_t *)o->v)));
	OR(o->p.length == 4, SIZE_3(*((uint64_t *)o->v)));
	OR(o->p.length == 8, SIZE_4(*((uint64_t *)o->v)));
	OR(o->p.length > 8, SIZE_5(*((uint64_t *)o->v)));
}

/*
**	#-> if(x==8) -> va_arg(o->ap, uint64_t) & (~0ULL >> (64 - x * 8))
**	#include "ft_printf.h"
**	#define U_VLS(u)	((u)!='d'||(u)!='i')
**	#define UC	typedef unsigned char	uc_t
**	#define US	typedef unsigned short	us_t
**
**	UC;
**	US;
**
**	void
**	//	->ap, o->v, &o->p, U_VLS(ft_tolower(o->str[0]))
**	//	cast_o(va_list ap, int64_t *n, t_param *parm, int u)
**		cast_o(t_format *o)
**	{
**		char	u;
**		int64_t	*n;
**
**		n = o->v;
**		u = U_VLS(ft_tolower(o->str[0]));
**		IF_E(!o->p.length,
**	n[0] = u ? (uint64_t)(uint)va_arg(o->ap, int) : (int64_t)(int)va_arg(o->ap, int),
**		IF_E(o->p.length & hh,
**	n[0] = u ? (uint64_t)(uc_t)va_arg(o->ap, int) : (int64_t)(char)va_arg(o->ap, int),
**		IF_E(o->p.length & h,
** n[0] = u ? (uint64_t)(us_t)va_arg(o->ap, int) : (int64_t)(short)va_arg(o->ap, int),
**		IF_E(o->p.length & l,
**		n[0] = u ? (uint64_t)va_arg(o->ap, long) : (int64_t)va_arg(o->ap, long),
**		IF_E(o->p.length & ll,
**		n[0] = u ? (uint64_t)va_arg(o->ap, uint64_t) : (int64_t)va_arg(o->ap, int64_t),
**		IF_E(o->p.length & j,
**	n[0]= u ? (uint64_t)va_arg(o->ap, uintmax_t) : (int64_t)va_arg(o->ap, intmax_t),
**		IF_C(o->p.length & z || o->p.length & t,
** n[0]= u ? (uint64_t)va_arg(o->ap, size_t) : (int64_t)va_arg(o->ap, ssize_t))))))));
**		IF_E(u, o->p.flags &= ~neg, o->p.flags |= (n[0] < 0) * neg);
**		return ;
**	}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:37:49 by viwade            #+#    #+#             */
/*   Updated: 2020/01/19 11:07:20 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H
# include <stdlib.h>
# include <sys/types.h>
# include "libft.h"

/*
**	--	DATA TYPE DEFINITIONS	--
**	A perfunctory glossary of uniform data types, which will be used to
**	assist in clarifying return values and desired argument types.
*/

# define FT_SIZE	size_t
# define FT_SSIZE	ssize_t
# define FT_NBR		t_num
# define FT_STR		caddr_t
# define FT_WSTR	caddr_t
# define FT_LSTR	int *
# define FT_TSTR	t_str
# define FT_INT		int
# define FT_UINT	UINT
# define FT_LIST	t_list *
# define FT_VOID	void
# define FT_VOIDP	void *
# define FT_D		double
# define FT_LD		long double
# define FT_FLOAT	float
# define FT_LL		LONG
# define FT_ULL		unsigned long long

/*
**	--	DATA TYPE SHORTHAND	--
*/

# define LL	FT_LL
# define ULL FT_ULL
# define NBR t_num
# define RET		return
# define RETURN		return
# define BREAK		break

# define ABS	ft_abs
# define MIN	ft_min
# define MAX	ft_max
# define SQ		ft_square
# define PYTH	ft_pythagorean

/*
**	TYPE DEFINITION
*/

# define _TD		typedef
# define _TD_LD		long double
# define _TD_D		typedef double	db_t
# define _TD_LL		typedef long long	ll_t
# define _TD_ULL	typedef unsigned long long	ull_t
# define _TD_BSTR	typedef struct s_byte_string bstr_t

// _TD int	i32_t;
_TD;
_TD_LD;
_TD_D;
_TD_LL;
_TD_ULL;
_TD_BSTR;

#endif

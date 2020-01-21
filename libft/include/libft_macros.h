/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:37:49 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 14:51:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include "libft.h"

typedef void *	t_vptr;
typedef char *	t_cptr;
typedef int *	t_iptr;
typedef double	t_db;
typedef long long	t_ll;
typedef long double	t_ld;
typedef unsigned long long	t_ull;
typedef unsigned long	t_ul;

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
# define FT_LSTR	intptr_t
# define FT_TSTR	t_str
# define FT_INT		int
# define FT_UINT	uint
# define FT_LIST	t_list
# define FT_VOID	void
# define FT_D		double_t
# define FT_LD		double_t
# define FT_FLOAT	float
# define LL_T		int64_t
# define ULL_T		u_int64_t

/*
**	--	DATA TYPE SHORTHAND	--
*/

# define LL		int64_t
# define ULL	uint64_t
# define NBR	t_num
# define RET	return
# define RETURN	return
# define BREAK	break
# define ANY2	ft_any2

# define ABS	ft_abs
# define MIN	ft_min
# define MAX	ft_max
# define SQ		ft_square
# define PYTH	ft_pythagorean_theorem

/*
**	TYPE DEFINITION
**	define _TD_LD	typedef long double ld_t
**	define _TD_D	typedef double	db_t
**	define _TD_LL	typedef long long	int64_t
**	define _TD_ULL	typedef unsigned long long	uint64_t
**	define _TD_BSTR	typedef struct s_byte_string bstr_t
*/

# ifdef _TD_LD

_TD_LD;
# endif

# ifdef _TD_D

_TD_D;
# endif

# ifdef _TD_LL

_TD_LL;
# endif

# ifdef _TD_ULL

_TD_ULL;
# endif

# ifdef _TD_BSTR

_TD_BSTR;
# endif

#endif

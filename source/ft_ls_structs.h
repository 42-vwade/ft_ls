/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2019/09/22 01:58:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCTS_H
# define FT_LS_STRUCTS_H
# include "ft_ls.h"

/*
**	TYPE DEFINITION
*/

/*
**	typedef struct s_config	t_config;
*/

/*
**	STRUCTS
*/

union	u_config
{
	long	check;
	struct	s_config
	{
		unsigned char	l;
	};
};

#endif

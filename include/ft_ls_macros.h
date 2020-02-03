/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 11:59:36 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_MACROS_H
# define FT_LS_MACROS_H
# define LS_FLAGS	"-lRartGuS1"
# define LS_FLAGS0	"ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1"
# define LS_LFORM	"%s %*hi %-*s %-*s %*li %s %a%s\x1b[0m%s\n"
# define LS_LDEV	"%s %*hi %-*s %-*s %*i, %*i %s %a%s\x1b[0m%s\n"
# define LS_6MOS	15780000l

/*
**	# define PATH_MAX	1024 <-- I predicted this in syslimits.h, and it is so!
*/

#endif

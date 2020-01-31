/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_xcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:47:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 23:37:27 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	ls_xcheck(t_entry *e)
{
	int32_t		xattr;

	xattr = listxattr(e->fullname, NULL, 0, XATTR_NOFOLLOW);
	((xattr > 0) && (e->t.ext = '@')) ||
	(e->t.ext = ' ');
}

/*
**	To check extended security attributes
**	-->	add ls_xacl(e) at the end of this function.
**		This function is fully implemented, and requires no dependencies.
**
**	The reason this function is not included is due to <acl.h>
**		creating memory leaks through it's usage.
**	No easy remedy exists, to my knowledge, and no such documentation
**		is available via developer documentation nor source files.
*/

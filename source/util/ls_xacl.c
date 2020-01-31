/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_xacl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 23:28:54 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 23:38:53 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_xacl(t_entry *e)
{
	acl_t		acl;
	acl_entry_t	acl_e;

	acl = acl_get_link_np(e->fullname, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_e) == -1)
		(acl_free(acl) || 1) && (acl = 0);
	acl && (e->t.ext = '+') &&
	acl_free(acl);
}

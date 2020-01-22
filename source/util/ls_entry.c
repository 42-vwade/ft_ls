/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:42 by viwade            #+#    #+#             */
/*   Updated: 2020/01/22 08:56:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	set_table(t_ls *ls)
{
	uint16_t	t;

	(ls->td[0] < (t = ft_intlen(ls->cur->links)))
	&& (ls->td[0] = t);
	(ls->td[1] < (t = ft_strlen(ls->cur->uname)))
	&& (ls->td[1] = t);
	(ls->td[2] < (t = 1 + ft_strlen(ls->cur->gname)))
	&& (ls->td[2] = t);
	(ls->td[3] < (t = 1 + ft_intlen(ls->cur->size)))
	&& (ls->td[3] = t);
}

t_entry
	*ls_entry(t_entry *e, t_ls *ls)
{
	ft_bzero(e, sizeof(e[0]));
	ft_strncat(ft_strcpy(e->fullname, ls->cwd), ls->e->d_name, ls->e->d_namlen);
	ft_strncpy(e->name, ls->e->d_name, ls->e->d_namlen);
	(ls_stat(e) && ls_type(e) && (e->name[0] == '.') && (e->hidden = 1));
	if (ls->cur->t.t == 'd')
		ls_node_append(&ls->dirs, ls_node_new(ls->cur->fullname));
	(ls->maxlen < 1 + ls->e->d_namlen)
	&& (ls->maxlen = 1 + ls->e->d_namlen);
	ls->blocks += ls->cur->stat.st_blocks;
	set_table(ls);
	return (e);
}

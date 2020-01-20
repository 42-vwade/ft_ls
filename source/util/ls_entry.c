/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:42 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 10:02:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_entry
	*ls_entry(t_entry *e, t_ls *ls)
{
	ft_bzero(e, sizeof(e[0]));
	ft_strncat(ft_strcpy(e->fullname, ls->cwd), ls->e->d_name, ls->e->d_namlen);
	(ls_stat(e) && ls_type(e) && (e->name[0] == '.') && (e->hidden = 1));
	if (ls->cur->t.t == 'd')
		ls_node_append(&ls->dirs, ls_node_new(ls->cur->fullname));
	(ls->maxlen < ls->e->d_namlen) && (ls->maxlen = ls->e->d_namlen);
	ls->blocks += ls->cur->stat.st_blocks;
	return (e);
}

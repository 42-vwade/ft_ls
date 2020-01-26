/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:42 by viwade            #+#    #+#             */
/*   Updated: 2020/01/25 23:06:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	set_table(t_ls *ls)
{
	uint16_t	t;

	(ls->td[0] < (t = ft_intlen(ls->cur->links)))
	&& (ls->td[0] = t);
	(ls->td[1] < (t = 1 + ft_strlen(ls->cur->uname)))
	&& (ls->td[1] = t);
	(ls->td[2] < (t = 1 + ft_strlen(ls->cur->gname)))
	&& (ls->td[2] = t);
	(ls->td[3] < (t = ft_intlen(ls->cur->size)))
	&& (ls->td[3] = t);
}

static int
	can_read(t_entry *e)
{
	return ((e->t.other[0] == 'r'));
}

static int
	ls_time(t_ls *ls)
{
	t_entry	*e;

	e = ls->cur;
	((ls->flags.u)
	&& ((e->mtime = e->stat.st_atimespec.tv_sec) || 1))
	|| (e->mtime = e->stat.st_mtimespec.tv_sec);
	((e->mtime < (long)time(0) - 15780000l)
	&& ft_strncpy(e->ctime, &ctime(&e->mtime)[4], 7)
	&& ft_strncpy(&e->ctime[7], &ctime(&e->mtime)[19], 5))
	|| ft_strncpy(e->ctime, &ctime(&e->mtime)[4], sizeof(e->ctime) - 1);
	return (1);
}

t_entry
	*ls_entry(t_entry *e, t_ls *ls)
{
	ft_bzero(e, sizeof(e[0]));
	ft_strncat(ft_strcpy(e->fullname, ls->cwd), ls->e->d_name, ls->e->d_namlen);
	ft_strncpy(e->name, ls->e->d_name, ls->e->d_namlen);
	(ls_stat(e) && (ls_time(ls) && ls_type(e)
	&& (ls->blocks += ls->cur->stat.st_blocks)
	&& (e->name[0] == '.' && (e->hidden = 1))));
	if (ls->cur->t.t == 'd' && can_read(e)
		&& (!ft_strnequ(".", e->name, 2) && !ft_strnequ("..", e->name, 3)))
		ls_node_append(&ls->dirs, ls_node_new(ls->cur->fullname));
	(ls->maxlen < 1 + ls->e->d_namlen)
	&& (ls->maxlen = 1 + ls->e->d_namlen);
	e->rev = ls->flags.r;
	set_table(ls);
	return (e);
}

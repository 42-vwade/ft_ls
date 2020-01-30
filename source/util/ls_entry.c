/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:42 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 04:26:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
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
	ls_time(const t_flags *f, t_entry *e)
{
	((f->u) && ((e->mtime = e->stat.st_atimespec.tv_sec) || 1))
	|| (e->mtime = e->stat.st_mtimespec.tv_sec);
	((e->mtime < (long)time(0) - LS_6MOS)
	&& ft_strncpy(e->ctime, &ctime(&e->mtime)[4], 7)
	&& ft_strncpy(&e->ctime[7], &ctime(&e->mtime)[19], 5))
	|| ft_strncpy(e->ctime, &ctime(&e->mtime)[4], sizeof(e->ctime) - 1);
	return (1);
}

static int
	ls_device(t_entry *e, t_ls *ls)
{
	size_t	t;

	if (e->t.t != 'c')
		return (0);
	e->dev_major = major(e->stat.st_rdev);
	e->dev_minor = minor(e->stat.st_rdev);
	(ls->dev[0] < (char)(t = 1 + ft_intlen(e->dev_major)))
	&& (ls->dev[0] = t);
	(ls->dev[1] < (char)(t = ft_intlen(e->dev_minor)))
	&& (ls->dev[1] = t);
	(ls->td[3] < (t = ls->dev[0] + ls->dev[1] + 2))
	&& (ls->td[3] = t);
	return (1);
}

t_entry
	*ls_entry(t_entry *e, t_ls *ls)
{
	ft_bzero(e, sizeof(e[0]));
	ft_strncat(ft_strcpy(e->fullname, ls->cwd), ls->e->d_name, ls->e->d_namlen);
	ft_strncpy(e->name, ls->e->d_name, ls->e->d_namlen);
	(ls_stat(e) && (ls_time(&ls->flags, e) && ls_type(e)
	&& (ls->blocks += e->stat.st_blocks)
	&& (e->name[0] == '.' && (e->hidden = 1))));
	if (e->t.t == 'd' && can_read(e)
		&& (!ft_strnequ(".", e->name, 2) && !ft_strnequ("..", e->name, 3)))
		ls_node_append(&ls->dirs, ls_node_new(e->fullname));
	(ls->maxlen < 4 + ls->e->d_namlen)
	&& (ls->maxlen = 4 + ls->e->d_namlen);
	e->rev = ls->flags.r;
	set_table(ls);
	ls->flags.l && ls_device(e, ls);
	return (e);
}

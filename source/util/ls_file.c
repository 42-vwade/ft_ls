/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:12:11 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 00:57:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	exit_call(const t_param *p, char *fn)
{
	ft_printf(
		"%s: ls_file: %s: %s [%i]\n",
		p->prgnm, ft_basename(fn), strerror(errno), errno);
	return (0);
}

static int
	end_file(int fd)
{
	close(fd);
	return (1);
}

static int
	ls_time(const t_param *p, t_entry *e)
{
	((p->f.u) && ((e->mtime = e->stat.st_atimespec.tv_sec) || 1))
	|| (e->mtime = e->stat.st_mtimespec.tv_sec);
	((e->mtime < (long)time(0) - LS_6MOS)
	&& ft_strncpy(e->ctime, &ctime(&e->mtime)[4], 7)
	&& ft_strncpy(&e->ctime[7], &ctime(&e->mtime)[19], 5))
	|| ft_strncpy(e->ctime, &ctime(&e->mtime)[4], sizeof(e->ctime) - 1);
	return (1);
}

static void
	ls_print(const t_param *p, t_entry *e)
{
	uint16_t	td[4];

	td[0] = ft_intlen(e->links);
	td[1] = 1 + ft_strlen(e->uname);
	td[2] = 1 + ft_strlen(e->gname);
	td[3] = ft_intlen(e->size);
	((p->f.l) && ft_printf(LS_LFORM, (char*)&e->t, td[0], e->links,
	td[1], e->uname, td[2], e->gname, td[3], e->size,
	e->ctime, e->name, e->name_ext))
	|| ft_printf("%s%.*s", e->name, p->f.n1, "\n");
}

int
	ls_file(const t_param *p, char *fn, int fd)
{
	t_entry		e;

	if (fd == -1)
		return (exit_call(p, fn));
	ft_bzero(&e, sizeof(e));
	ft_strncpy(e.name, ft_basename(fn), NAME_MAX) &&
	ft_strncpy(e.fullname, fn, PATH_MAX);
	(ls_stat(&e) && (ls_time(p, &e) && ls_type(&e)))
	|| ft_printf("error setting stat for: &s", e.fullname);
	ls_print(p, &e);
	return (end_file(fd));
}

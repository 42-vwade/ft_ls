/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:58:46 by viwade            #+#    #+#             */
/*   Updated: 2020/01/26 16:29:51 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	ls_display(t_ls *ls)
{
	t_node	*node;
	t_entry	*e;

	(ls->flags.l)
	&& ft_printf("%s%i\n", "total ", ls->blocks);
	node = ls->list;
	while (node)
	{
		e = node->content;
		((ls->flags.l)
		&& ft_printf(LS_LFORM, (char*)&e->t, ls->td[0], e->links,
		ls->td[1], e->uname, ls->td[2], e->gname, ls->td[3], e->size,
		e->ctime, e->name, e->name_ext))
		|| ft_printf("%-*s%.*s", ls->maxlen, e->name, ls->flags.n1 | 1, "\n");
		node = node->next;
	}
}

static void
	ls_build_list(t_ls *ls)
{
	while ((ls->e = readdir(ls->dir)))
	{
		if (ls->e->d_name[0] != '.' || ls->flags.a)
			ls_node_append(&ls->list,
			ls_node_new(ls_entry(ls->cur = malloc(sizeof(t_entry)), ls)));
	}
	((ls->cmp != ls_rstrcmp || ls->cmp != ls_strcmp)
	&& (ls->list = ls_merge_sort(ls->list, ls_strcmp)));
	ls->list = ls_merge_sort(ls->list, ls->cmp);
	ls_display(ls);
}

static void
	ls_end(const t_param *p, t_ls *ls)
{
	t_node	*node;

	while ((node = ls->dirs))
	{
		(p->f.rr) && (ft_printf("\n%s:\n", node->content) || 1)
		&& ft_ls(p, node->content);
		(ls->dirs = node->next);
		ft_memdel((void**)&node);
	}
	while ((node = ls->list))
	{
		ft_memdel((void**)&node->content);
		(ls->list = node->next);
		ft_memdel((void**)&node);
	}
}

static int
	exit_call(const t_param *p)
{
	ft_printf(
		"%s: %s: %s [%i]\n",
		p->prgnm, p->cwd, strerror(errno), errno);
	return (errno);
}

int
	ft_ls(const t_param *parameters, char *directory)
{
	t_ls	ls;

	ft_bzero(&ls, sizeof(ls));
	ft_memcpy((void*)&ls.flags, &parameters->f, sizeof(t_flags));
	ls_dir(ft_strcpy(ls.cwd, directory));
	if (!(ls.dir = opendir(ls.cwd)))
		return (exit_call(parameters));
	ls.cmp = parameters->cmp;
	ls_build_list(&ls);
	closedir(ls.dir);
	ls_end(parameters, &ls);
	return (errno);
}

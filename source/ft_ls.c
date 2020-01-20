/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:58:46 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 12:19:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	exit_call(char *pathname)
{
	ft_printf("ft_ls: %s: %s [%i]\n", pathname, strerror(errno), errno);
	return (errno);
}

static void
	ls_build_list(t_ls *ls)
{
	while ((ls->e = readdir(ls->dir)))
	{
		if (ls->e->d_name[0] != '.' || ls->param.f.a)
			ls_node_append(&ls->list,
			ls_node_new(ls_entry(ls->cur = malloc(sizeof(t_entry)), ls)));
	}
}

static void
	ls_end(const t_param *p, t_ls *ls)
{
	t_node	*node;
	t_entry	*e;

	while ((node = ls->list))
	{
		e = node->content;
		ft_memdel((void**)&e->name);
		ls->list = node->next;
		ft_memdel((void**)&node);
	}
	node = ls->dirs;
	while (p->f.rr && node)
	{
		ft_printf("\n%s:\n", node->content) && ft_ls(p, node->content);
		(node = node->next);
	}
	ls_lstdel(ls->dirs);
}

int
	ft_ls(const t_param *parameters, char *directory)
{
	t_ls	ls;

	ft_bzero(&ls, sizeof(ls));
	if (!(ls.dir = opendir(directory)))
		return (exit_call(directory));
	ls.cwd = directory;
	ls_build_list(&ls);
	closedir(ls.dir);
	ls_end(parameters, &ls);
	return (errno);
}

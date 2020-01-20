/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:58:46 by viwade            #+#    #+#             */
/*   Updated: 2020/01/19 09:35:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	exit_call(void)
{
	printf("opendir: error[%i]: %s\n", errno, strerror(errno));
	return (errno);
}

static t_entry
	*ls_entry(t_entry *e, t_dirent *dir, char *cwd)
{

	ft_strcpy(ft_strcpy(e->fullname, cwd), dir->d_name);
	return (e);
}

static void
	ls_build_list(t_ls *ls)
{

	while ((ls->e = readdir(ls->dir)))
	{
		ls_node_append(&ls->list,
		ls_node_new(
		ls_entry(
			malloc(sizeof(t_entry)), ls->cwd)));
	}
}

static void
	ls_del(t_node *node)
{
	t_node	*tmp;
	t_entry	*e;

	while ((tmp = node))
	{
		e = node->content;
		ft_memdel(&e->name);
		node = node->next;
		ft_memdel(&tmp);
	}
}

int
	ft_ls(t_param parameters, char *directory)
{
	t_ls	ls;

	ft_bzero(&ls, sizeof(ls));
	if (!(ls.dir = opendir(directory)))
		return (exit_call());
	ls.cwd = directory;
	ls_build_list(&ls);
	closedir(directory);
	while (parameters.f.rr && ls.dirs)
		ft_ls(parameters, ls.dirs->content);
	return (0);
}

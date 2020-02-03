/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:58:46 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 12:14:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	ls_build_list(t_ls *ls)
{
	while ((ls->e = readdir(ls->dir)))
	{
		if (ls->e->d_name[0] != '.' || ls->flags.a)
			ls_node_append(&ls->list,
			ls_node_new(ls_entry(ls->cur = malloc(sizeof(t_entry)), ls)));
	}
	((ls->cmp != ls_rstrcmp || ls->cmp != ls_strcmp) &&
	((ls->flags.r
		&& ((ls->list = ls_merge_sort(ls->list, ls_rstrcmp)) || 1)
		&& ((ls->dirs = ls_merge_sort(ls->dirs, ls_rstrcmp)) || 1))
	|| (((ls->list = ls_merge_sort(ls->list, ls_strcmp)) || 1)
	&& ((ls->dirs = ls_merge_sort(ls->dirs, ls_strcmp)) || 1))));
	ls->list = ls_merge_sort(ls->list, ls->cmp);
	ls->dirs = ls_merge_sort(ls->dirs, ls->cmp);
	ls_single(ls) || ls_list(ls) || ls_columns(ls);
}

static void
	ls_end(const t_param *p, t_ls *ls)
{
	t_node	*node;

	while ((node = ls->dirs))
	{
		(p->f.rr)
		&& (ft_printf("\n%s:\n", ((t_entry*)node->content)->fullname) || 1)
		&& ft_ls(p, ((t_entry*)node->content)->fullname);
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
	exit_call(const t_param *p, char *pathname)
{
	ft_printf(
		"%s: %s: %s [%i]\n",
		p->prgnm, pathname, strerror(errno), errno);
	return (errno);
}

int
	ft_ls(const t_param *parameters, char *directory)
{
	t_ls	ls;

	ft_bzero(&ls, sizeof(ls));
	ls.cmp = parameters->cmp;
	ft_memcpy((void*)&ls.flags, &parameters->f, sizeof(t_flags));
	ls_dir(ft_strcpy(ls.cwd, directory));
	if (!(ls.dir = opendir(ls.cwd)) && (errno == ENOTDIR))
		return (ls_file(parameters, directory, open(directory, O_RDONLY)));
	else if (!ls.dir)
		return (exit_call(parameters, ft_basename(directory)));
	ls_build_list(&ls);
	closedir(ls.dir);
	ls_end(parameters, &ls);
	return (errno);
}

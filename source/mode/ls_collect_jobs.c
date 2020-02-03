/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_collect_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:57:12 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 10:28:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ls_namesort(t_node *a, t_node *b)
{
	char	*left;
	char	*right;

	left = a->content;
	right = b->content;
	return (ft_strcmp(left, right) > 0);
}

int
	ls_rnamesort(t_node *a, t_node *b)
{
	char	*left;
	char	*right;

	left = a->content;
	right = b->content;
	return (ft_strcmp(left, right) < 0);
}

int
	ls_timesort(t_node *a, t_node *b)
{
	t_stat	left;
	t_stat	right;

	lstat(a->content, &left);
	lstat(b->content, &right);
	return (left.st_mtimespec.tv_sec < right.st_mtimespec.tv_sec);
}

int
	ls_rtimesort(t_node *a, t_node *b)
{
	t_stat	left;
	t_stat	right;

	lstat(a->content, &left);
	lstat(b->content, &right);
	return (left.st_mtimespec.tv_sec > right.st_mtimespec.tv_sec);
}

t_node
	*ls_collect_paths(t_param *p)
{
	char	**v;
	t_node	*paths;
	t_node	*node;
	int		(*f)(t_node*, t_node*);

	v = p->v;
	paths = 0;
	((p->f.t) && (f = p->f.r ? ls_rtimesort : ls_timesort)) ||
	(f = p->f.r ? ls_rtimesort : ls_timesort);
	while (*v || ((node = paths) && 0))
		ls_node_append(&paths, ls_node_new(ls_strtrim(*v++)));
	paths && (paths = ls_merge_sort(paths, f));
	return (paths);
}

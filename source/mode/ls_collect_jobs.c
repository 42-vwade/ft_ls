/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_collect_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:57:12 by viwade            #+#    #+#             */
/*   Updated: 2020/02/02 18:03:22 by viwade           ###   ########.fr       */
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

t_node
	*ls_collect_paths(t_param *p)
{
	char	**v;
	t_node	*paths;
	t_node	*node;

	v = p->v;
	paths = 0;
	while (*v || ((node = paths) && 0))
		ls_node_append(&paths, ls_node_new(ls_strtrim(*v++)));
	paths && ((p->f.r &&
	((paths = ls_merge_sort(paths, ls_rnamesort)) || 1)) ||
	((paths = ls_merge_sort(paths, ls_namesort))));
	return (paths);
}

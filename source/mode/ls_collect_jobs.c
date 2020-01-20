/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_collect_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:57:12 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 02:48:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node
	*ls_collect_paths(char **v)
{
	t_node	*paths;

	paths = 0;
	while (*v)
		ls_node_append(&paths, ls_node_new(*v++));
	ls_merge_sort(paths, ls_strcmp);
	return (paths);
}

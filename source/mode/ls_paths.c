/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:39:49 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 03:03:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ls_paths(const t_param *parameters, t_node *node)
{
	t_node	*tmp;
	DIR		*dir;

	while (node)
	{
		tmp = node;
		if ((dir = opendir(node->content)))
			ft_printf("%s:\n", node->content) && closedir(dir);
		ft_ls(parameters, node->content);
		if ((node = node->next) &&
			(dir = opendir(node->content)))
			write(1, "\n", 1) && closedir(dir);
		ft_memdel((void**)&tmp);
	}
	return (1);
}

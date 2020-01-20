/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:39:49 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 12:20:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ls_paths(const t_param *parameters, t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node;
		ft_printf("%s:\n", node->content);
		ft_ls(parameters, node->content);
		if ((node = node->next))
			write(1, "\n", 1);
		ft_memdel((void**)&tmp);
	}
	return (1);
}

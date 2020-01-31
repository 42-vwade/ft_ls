/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:39:49 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 22:43:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	node_remove(t_node **parent, void *node)
{
	t_node	*seek;

	if (!parent[0] && ((parent[0] = ((t_node *)node)->next) || 1))
		return (ft_memdel(&node));
	else if (parent[0] == node && ((parent[0] = ((t_node *)node)->next) || 1))
		return (ft_memdel(&node));
	seek = parent[0];
	while (seek->next != node)
		seek = seek->next;
	seek->next = ((t_node *)node)->next;
	ft_memdel(&node);
}

static void
	error_remove(t_node **start, const t_param *p)
{
	DIR		*dir;
	t_node	*node;
	t_node	*next;
	t_node	*first;

	first = 0;
	node = *start;
	while ((node))
	{
		next = node->next;
		if (!(dir = opendir(node->content)) && errno != 20)
		{
			ft_ls(p, node->content);
			node_remove(&first, node);
		}
		else if (!first)
			first = node;
		node = next;
	}
	*start = first;
}

static void
	list_files(t_node **start, const t_param *p)
{
	DIR		*dir;
	t_node	*node;
	t_node	*next;
	t_node	*first;
	int32_t	if_error;

	first = 0;
	if_error = 0;
	node = *start;
	while ((node))
	{
		next = node->next;
		if (!(dir = opendir(node->content)) && errno == 20)
		{
			!if_error && (if_error = 1);
			ft_ls(p, node->content);
			node_remove(&first, node);
		}
		else if (!first)
			first = node;
		node = next;
	}
	if_error && first && write(1, "\n", 1);
	*start = first;
}

int
	ls_paths(const t_param *parameters, t_node *node)
{
	t_node	*tmp;
	DIR		*dir;

	error_remove(&node, parameters);
	list_files(&node, parameters);
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

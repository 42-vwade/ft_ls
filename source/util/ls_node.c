/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:18:19 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 20:18:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node
	*ls_node_new(void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->content = content;
	new->next = 0;
	return (new);
}

void
	ls_node_append(t_node **node, t_node *new)
{
	t_node	*push;

	if ((!node[0]) && ((node[0] = new) || 1))
		return ;
	push = node[0];
	while (push->next)
		push = push->next;
	push->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 02:01:55 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_single(t_ls *ls)
{
	t_node	*node;
	t_entry	*e;

	if (!ls->flags.n1)
		return (0);
	node = ls->list;
	while (node)
	{
		e = node->content;
		ft_printf("%s%s", e->name, "\n");
		node = node->next;
	}
	return (1);
}

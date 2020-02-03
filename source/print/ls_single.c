/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/02/02 17:35:36 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	print_form(t_node *node)
{
	t_entry	*e;

	while (node)
	{
		e = node->content;
		ft_printf("%s%s", e->name, "\n");
		node = node->next;
	}
}

int
	ls_single(t_ls *ls)
{
	if ((!ls->flags.n1))
		return (0);
	print_form(ls->list);
	return (1);
}

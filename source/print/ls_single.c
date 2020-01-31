/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_single.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 10:03:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	print_form(t_node *node)
{
	void	*output;
	t_entry	*e;

	output = 0;
	while (node)
	{
		e = node->content;
		(output &&
		(output = ft_append(output, ft_sprintf("%s%s", e->name, "\n"), 3))) ||
		(output = ft_sprintf("%s%s", e->name, "\n"));
		node = node->next;
	}
	ft_printf("%s", output);
	ft_memdel(&output);
}

int
	ls_single(t_ls *ls)
{
	if ((!ls->flags.n1))
		return (0);
	print_form(ls->list);
	return (1);
}

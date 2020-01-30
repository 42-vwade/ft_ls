/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 04:01:55 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	print_normal(t_entry *e, t_ls *ls)
{
	ft_printf(LS_LFORM, (char*)&e->t, ls->td[0], e->links,
	ls->td[1], e->uname, ls->td[2], e->gname, ls->td[3], e->size,
	e->ctime, e->name, e->name_ext);
	return (1);
}

static int
	print_device(t_entry *e, t_ls *ls)
{
	if (e->t.t != 'c')
		return (0);
	ft_printf(LS_LDEV, (char*)&e->t, ls->td[0], e->links,
	ls->td[1], e->uname, ls->td[2], e->gname,
	ls->dev[0], e->dev_major, ls->dev[1], e->dev_minor,
	e->ctime, e->name, e->name_ext);
	return (1);
}

int
	ls_list(t_ls *ls)
{
	t_node	*node;

	if (!ls->flags.l)
		return (0);
	node = ls->list;
	ft_printf("%s%i\n", "total ", ls->blocks);
	while (node)
	{
		print_device(node->content, ls) || print_normal(node->content, ls);
		node = node->next;
	}
	return (1);
}

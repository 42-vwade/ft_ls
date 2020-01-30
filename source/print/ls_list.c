/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 02:00:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_list(t_ls *ls)
{
	t_node	*node;
	t_entry	*e;

	if (!ls->flags.l)
		return (0);
	node = ls->list;
	ft_printf("%s%i\n", "total ", ls->blocks);
	while (node)
	{
		e = node->content;
		ft_printf(LS_LFORM, (char*)&e->t, ls->td[0], e->links,
		ls->td[1], e->uname, ls->td[2], e->gname, ls->td[3], e->size,
		e->ctime, e->name, e->name_ext);
		node = node->next;
	}
	return (1);
}

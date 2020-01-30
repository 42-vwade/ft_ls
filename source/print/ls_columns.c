/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/30 09:03:59 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct winsize	t_winsize;

int		ls_columns(t_ls *ls)
{
	t_node		*node;
	t_entry		*e;
	size_t		i;
	t_winsize	w;

	node = ls->list;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while (node && !(i = 0))
	{
		while (node && i++ < w.ws_col / ls->maxlen)
			((e = node->content) || 1) &&
			(ft_printf("%-*s", ls->maxlen, e->name) || 1) &&
			(node = node->next);
		write(1, "\n", 1);
		(node) && (node = node->next);
	}
	return (1);
}

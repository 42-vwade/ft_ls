/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 12:12:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct winsize	t_winsize;

static void
	print_form(t_node *node, t_ls *ls, int64_t i, t_winsize *w)
{
	t_entry		*e;

	while (node && !(i = 0))
	{
		while (node && i++ < w->ws_col / ls->maxlen)
			((e = node->content) || 1) &&
			(ft_printf("%a%-*s\x1b[0m", e->color, ls->maxlen, e->name)) &&
			(node = node->next);
		(node) && (node = node->next);
		write(1, "\n", 1);
	}
}

int
	ls_columns(t_ls *ls)
{
	t_winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	print_form(ls->list, ls, 0, &w);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 00:58:27 by viwade            #+#    #+#             */
/*   Updated: 2020/01/31 10:07:32 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct winsize	t_winsize;

static void
	print_form(t_node *node, t_ls *ls, int64_t i, t_winsize *w)
{
	void		*output;
	t_entry		*e;

	output = 0;
	while (node && !(i = 0))
	{
		while (node && i++ < w->ws_col / ls->maxlen)
			((e = node->content) || 1) &&
			(((output &&
		(output = ft_append(output,
			ft_sprintf("%-*s", ls->maxlen, e->name), 3))) ||
		(output = ft_sprintf("%-*s", ls->maxlen, e->name))) || 1) &&
			(node = node->next);
		output = ft_append(output, "\n", 1);
		(node) && (node = node->next);
	}
	ft_printf("%s", output);
	ft_memdel(&output);
}

int
	ls_columns(t_ls *ls)
{
	t_winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	print_form(ls->list, ls, 0, &w);
	return (1);
}

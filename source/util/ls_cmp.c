/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:39:48 by viwade            #+#    #+#             */
/*   Updated: 2020/01/25 22:31:18 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ls_strcmp(t_node *a, t_node *b)
{
	t_entry	*left;
	t_entry	*right;

	left = a->content;
	right = b->content;
	return (ft_strcmp(left->name, right->name) > 0);
}

int
	ls_tcmp(t_node *a, t_node *b)
{
	t_entry	*left;
	t_entry	*right;

	left = a->content;
	right = b->content;
	return (left->mtime < right->mtime);
}

int
	ls_sizcmp(t_node *a, t_node *b)
{
	t_entry	*left;
	t_entry	*right;

	left = a->content;
	right = b->content;
	return (left->size < right->size);
}

int
	ls_ltcmp(t_node *a, t_node *b)
{
	t_entry	*left;
	t_entry	*right;

	left = a->content;
	right = b->content;
	return (left->stat.st_atimespec.tv_sec < right->stat.st_atimespec.tv_sec);
}

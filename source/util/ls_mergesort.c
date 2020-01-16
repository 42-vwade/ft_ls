/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:07:07 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 20:19:21 by viwade           ###   ########.fr       */
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
	ls_sizcmp(t_node *a, t_node *b)
{
	t_entry	*left;
	t_entry	*right;

	left = a->content;
	right = b->content;
	return (left->size > right->size);
}

static t_node
	*node_merge(t_node *a, t_node *b, int (*f)(t_node*, t_node*))
{
	t_node	*result;

	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (f(a, b))
		((result = b) || 1) &&
		(result->next = node_merge(a, b->next, f));
	else
		((result = a) || 1) &&
		(result->next = node_merge(a->next, b, f));
	return (result);
}

static void
	node_split(t_node *src, t_node **a, t_node **b)
{
	t_node	*fast;
	t_node	*slow;

	slow = src;
	fast = src->next;
	while (fast)
		if ((fast = fast->next))
			((slow = slow->next) || 1) &&
			(fast = fast->next);
	a[0] = src;
	b[0] = slow->next;
	slow->next = 0;
}

t_node
	*ls_merge_sort(t_node *node, int (*f)(t_node*, t_node*))
{
	t_node	*left;
	t_node	*right;

	if ((!node || !node->next))
		return (node);
	node_split(node, &left, &right);
	return (node_merge(ls_merge_sort(left, f), ls_merge_sort(right, f), f));
}

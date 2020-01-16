/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c.m                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 09:42:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 18:56:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stack	ls_sort(t_stack *stack)
{
	t_dir	*dir[2];
	t_node	*node;
	int		is_sorted;

	if (!stack || !stack->top)
		ft_error("ls_sort: invalid stack given");
	is_sorted = 0;
	while (!is_sorted)
	{
		node = stack->top;
		while (node && node->next)
		{
			dir[0] = node->content;
			dir[1] = node->next->content;
			if (ft_strcmp(dir[0]->name, dir[1]->name) > 1)
				ft_swap()
		}
	}
}

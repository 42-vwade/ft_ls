/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:57:12 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 20:18:11 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node
	*ls_directory(char **v)
{
	t_node	*pointer;

	pointer = 0;
	while (*v)
		ls_node_append(&pointer, ls_node_new(*v++));
	ls_merge_sort(pointer, ls_strcmp);
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:58:36 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 12:30:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	ls_cwd(char *argv0, char path[PATH_MAX])
{
	int i;
	int last;

	i = 0;
	while ((path[i] = argv0[i]) && i < PATH_MAX)
		last = i++;
	while (&path[last] >= path && path[last] != '/')
		last--;
	if (path[last] == '/' && ++last < PATH_MAX)
		path[last] = 0;
	return ;
}

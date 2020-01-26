/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:32:07 by viwade            #+#    #+#             */
/*   Updated: 2020/01/26 15:28:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ls_dir(char s[PATH_MAX])
{
	size_t	len;

	len = ft_strlen(s);
	(((len && s[len - 1] != '/' && len + 1 < PATH_MAX)) && (s[len] = '/')
	&& (s[len + 1] = 0));
	return (1);
}

/*
**	edge cases:
**		string length must be at least 1
**		last char is not '/'
**		total length of string + 1 is less than PATH_MAX
*/

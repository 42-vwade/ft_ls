/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 04:09:54 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:51:45 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t
	*ft_strtol(char *s)
{
	int64_t	*new;
	size_t		i;

	if (!s || !(new = (int64_t*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		new[i - 1] = (int64_t)s[i - 1];
	return (new);
}

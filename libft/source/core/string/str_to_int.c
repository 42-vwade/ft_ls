/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 04:09:54 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:51:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t
	*ft_strtoi(char *s)
{
	int32_t	*new;
	size_t		i;

	if (!s || !(new = (int32_t*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		new[i - 1] = (int32_t)s[i - 1];
	return (new);
}

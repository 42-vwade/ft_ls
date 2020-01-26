/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:40:32 by viwade            #+#    #+#             */
/*   Updated: 2020/01/25 20:59:38 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_whitespace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

char		*ls_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if ((start = !s))
		return (0);
	start = 0;
	len = ft_strlen(s);
	while (is_whitespace(s[start]))
		start++;
	while (len && is_whitespace(s[len - 1]))
		len--;
	if (s[len])
		((char *)s)[len] = 0;
	return (&((char *)s)[start]);
}

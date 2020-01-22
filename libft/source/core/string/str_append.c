/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:55:41 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 13:05:38 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FREE_NONE	0
#define FREE_LEFT	1
#define FREE_RIGHT	2
#define FREE_ALL	3

static void
	append_mode(void **s, const void *a, const void *b, int m)
{
	s[0] = ft_strjoin(a, b);
	if (m & FREE_LEFT)
		ft_memdel((void**)&a);
	if (m & FREE_RIGHT)
		ft_memdel((void**)&b);
}

char
	*ft_append(const char *s1, const char *s2, int mode)
{
	void	*string;

	if ((string = (void*)(uint64_t)((uint32_t)mode > FREE_ALL)))
		ft_error("ft_append: no mode specified");
	(!s1 && (mode == 1 || mode == 3)) && (mode -= 1);
	(!s2 && (mode == 2 || mode == 3)) && (mode = mode == 3 ? 1 : 0);
	append_mode(&string, s1, s2, mode);
	return (string);
}

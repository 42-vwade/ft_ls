/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 02:48:54 by viwade            #+#    #+#             */
/*   Updated: 2019/05/27 12:20:09 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <string.h>

int64_t
	ft_wstrlen(wchar_t *s)
{
	wchar_t	*e;

	e = s;
	while (*(e += !!e[0]))
		;
	return ((e - s) / sizeof(wchar_t));
}

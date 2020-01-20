/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:07:14 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:32:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static uint32_t
	char_size(uint32_t c)
{
	return (1 + ((c) > 0x7f) || 3 * ((c) > 0x7ff) || 4 * ((c) > 0xffff));
}

void
	ft_putchar(int c)
{
	void	*tmp;

	tmp = 0;
	if (c)
	{
		(c > 0x7f) && (tmp = encode_utf8((int[]){c, 0}));
		((c > 0x7f) && write(1, tmp, 1 + char_size(c))) ||
		write(1, &c, 1);
		if (tmp)
			ft_memdel(&tmp);
	}
}

/*
**	Prints a character to stdout.
**	Can handle unicode characters.
**	Utilizes fast output calculation.
**	Do not to use for writing strings of characters. Use ft_putstr.
*/

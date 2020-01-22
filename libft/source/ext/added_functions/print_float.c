/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:02:58 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 13:06:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_float(float f, size_t precision)
{
	uint32_t	data;

	ft_memcpy(&data, &f, sizeof(f));
	print_memory(&f, sizeof(f));
	print_memory(&data, sizeof(data));
	if (precision)
		data = 0;
}

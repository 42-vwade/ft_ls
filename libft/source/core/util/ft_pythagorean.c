/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythagorean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:40:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 14:06:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double_t	ft_pythagorean_theorem(int64_t a, int64_t b, int64_t c)
{
	return (sqrt(SQ(a) + SQ(b) + SQ(c)));
}

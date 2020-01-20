/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythagorean_theorem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:40:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/17 23:41:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

long	ft_pythagorean(long a, long b, long c)
{
	return ((SQ(a) + SQ(b) + SQ(c)));
}

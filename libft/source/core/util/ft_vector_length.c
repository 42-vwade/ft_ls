/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:40:13 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:24:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double_t	ft_vector_length(t_v3d v)
{
	return (ft_pythagorean_theorem(v.x, v.y, v.z));
}

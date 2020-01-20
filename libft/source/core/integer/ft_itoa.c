/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:58:04 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:35:07 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

FT_STR
	ft_itoa(int64_t n)
{
	char	*ret;

	ret = ft_itoa_base(ABS(n), 10);
	if (n < 0)
		ret = ft_strjoin_free(ft_strdup("-"), ret);
	return (ret);
}

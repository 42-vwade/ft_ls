/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infinite_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:41:29 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:09:50 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

FT_STR
	infinite_int(int64_t n)
{
	char	*nbr;
	char	*tmp;

	tmp = NULL;
	nbr = ft_strdup("");
	if (n < 0 ? (n = ABS(n)) : 0)
		nbr = ft_strjoin_free(ft_strdup("-"), nbr);
	if (n >= 10 && (tmp = infinite_int(n / 10)))
		nbr = ft_strjoin_free(tmp, (char[2]){n % 10 + 48, 0});
	if (tmp)
		free(tmp);
	return (nbr);
}

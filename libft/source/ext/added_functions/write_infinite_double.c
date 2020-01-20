/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infinite_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:41:29 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:10:00 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int8_t
	next_decimal(double_t n)
{
	return (((n) - (int64_t)(n)) * 10);
}

static char
	*round_inf(char *s, char n)
{
	size_t	len;

	if (n < 5)
		return (s);
	len = ft_strlen(s);
	while (s < &s[len--])
		if (s[len] - 48 == 9)
			s[len] = 48;
		else
			break ;
	s[len] += 1;
	return (s);
}

static char
	*get_decimal(
		double_t n,
		size_t p)
{
	char	*dec;
	char	buf[2];
	size_t	i;

	i = 0;
	buf[1] = 0;
	while (n >= 1.0)
		n = (n - (int64_t)n);
	n = (n - (int64_t)n) * 10;
	dec = ft_memset(ft_strnew(p), 0, p);
	while (i < p)
	{
		if ((int64_t)n)
			ft_strcat(&dec[i], (char[2]){(int64_t)n + 48, 0});
		else
			ft_strcat(&dec[i], (char[2]){48, 0});
		n = (n - (int64_t)n) * 10;
		i += 1;
	}
	round_inf(dec, n);
	return (dec);
}

FT_SIZE
	write_infinite_double(
		double_t d,
		uint64_t p)
{
	FT_NBR	nbr;

	nbr.d = infinite_double(d, p);
	nbr.length = write(1, nbr.d, ft_strlen(nbr.d));
	free(nbr.d);
	return (nbr.length);
}

FT_STR
	infinite_double(
		double_t n,
		uint64_t p)
{
	char	*dec;
	FT_NBR	nbr[1];

	dec = p ? get_decimal(ABS(n), p) : NULL;
	n += dec && (dec[0] == '0' && next_decimal(n) == 9);
	nbr[0].d = ft_itoa((int64_t)n);
	if (p)
		nbr[0].d = ft_strjoin_free(
				nbr[0].d,
				ft_strjoin_free(
					ft_strdup("."),
					dec));
	return (nbr[0].d);
}

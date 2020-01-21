/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:26:11 by viwade            #+#    #+#             */
/*   Updated: 2020/01/21 11:58:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char
	*decode_str(const char *s, size_t *write)
{
	char	buf[2];
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	buf[1] = 0;
	len = ft_strlen(s);
	if (!(new = ft_strnew(len / 2)))
		ft_error("fatal: decode string failed");
	while (i < len)
	{
		buf[0] = (s[i] & 0x0f) | ((s[i + 1] & 0x0f) << 4);
		ft_strcat(&new[i / 2], buf);
		i += 2;
	}
	write[0] = len / 2;
	return (new);
}

static char
	*encode_str(const char *s)
{
	char	buf[3];
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	buf[2] = 0;
	(len = ft_strlen(s))
		|| (len = 1);
	if (!(new = ft_strnew(len * 2)))
		ft_error("fatal: encode string failed");
	while (i < len)
	{
		buf[0] = 0xf0 | (s[i] & 0x0f);
		buf[1] = 0xf0 | (s[i] >> 4);
		ft_strcat(&new[i * 2], buf);
		i += 1;
	}
	return (new);
}

char
	*encode_output(const char *data, const char *output)
{
	char	*encode;

	if (!output)
		RET((char *)data);
	((!data) && ((encode = encode_str(output)) || 1))
	|| (encode = ft_append(data, encode_str(output), 3));
	ft_memdel((void **)&output);
	return (encode);
}

char
	*decode_output(const char *data, size_t *len)
{
	char	*decode;

	((data) && ((decode = decode_str(data, len)) || 1))
	|| (decode = ft_strnew(0));
	ft_memdel((void **)&data);
	return (decode);
}

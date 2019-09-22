/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:01:36 by viwade            #+#    #+#             */
/*   Updated: 2019/09/21 19:17:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	parse_options(int n, char **v)
{
	int		i[2];

	i[0] = 0;
	while (++i[0] < n)
	{
		i[1] = 0;
		if (v[i[0]][0] == '-')

	}
}

int
	main(int n, char **v)
{
	t_config	config;

	ft_bzero(&config, sizeof(config));
	if (n > 1)
		parse_options(n, v);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:01:36 by viwade            #+#    #+#             */
/*   Updated: 2019/09/21 18:28:44 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void

int
	main(int n, char **v)
{
	t_config	config;

	ft_bzero(&config, sizeof(config));
	if (n > 1)
		parse_options(n, v);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:01:36 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 05:48:23 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	ls_parameters(t_param *p, int n, char **v)
{
	size_t	i;

	p->n = n;
	while (*v && v[0][0] == '-' && (i = 1))
		while ((v[0][i]) || ((v += 1) && 0))
			if (v[0][i] == '-' && ((v += 1) || 1))
				break ;
			else if ((v[0][i] == 'l') && ((i += 1) || 1))
				p->f.l = 1;
			else if ((v[0][i] == 'R') && ((i += 1) || 1))
				p->f.rr = 1;
			else if ((v[0][i] == 'a') && ((i += 1) || 1))
				p->f.a = 1;
			else if ((v[0][i] == 'r') && ((i += 1) || 1))
				p->f.r = 1;
			else if ((v[0][i] == 't') && ((i += 1) || 1))
				p->f.t = 1;
	p->v = v;
}

int
	main(int n, char **v)
{
	t_main	m;

	ft_bzero(&m, sizeof(m));
	m.prgnm = ft_basename(v[0]);
	ls_cwd(v[0], m.cwd);
	if ((n) == 1)
		return (ls_default(m.cwd));
	ls_parameters(&m.param, n, &v[1]);
	if (*m.param.v)
		m.jobs = ls_collect_paths(m.param.v);
	if (m.jobs && m.jobs->next)
		ls_paths(&m.param, m.jobs);
	else if (m.jobs && (ft_ls(&m.param, m.jobs->content) || 1))
		ft_memdel((void*)&m.jobs);
	else
		ft_ls(&m.param, m.cwd);
}

/*
**	init w/bzero. get cwd. if no param, do default. else do ls.
**	get params.
*/
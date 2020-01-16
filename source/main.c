/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:01:36 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 19:52:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#if 0

Comments and the like may freely go here, at least that is the hope.

#endif

static t_param
	ls_parameters(int n, char **v, t_flags *f)
{
	t_param	p;
	size_t	i;

	p.n = n;
	while (*v && !(i = 0))
		while ((v[0][i++] && v[0][0] == '-') || ((v += 1) && 0))
			if (v[0][i] == '-' && ((v += 1) || 1))
				break ;
			else if ((v[0][i] == 'l') && ((i += 1) || 1))
				f->l = 1;
			else if ((v[0][i] == 'R') && ((i += 1) || 1))
				f->rr = 1;
			else if ((v[0][i] == 'a') && ((i += 1) || 1))
				f->a = 1;
			else if ((v[0][i] == 'r') && ((i += 1) || 1))
				f->r = 1;
			else if ((v[0][i] == 't') && ((i += 1) || 1))
				f->t = 1;
	p.v = v;
	return (p);
}

int
	main(int n, char **v)
{
	t_main	m;

	ft_bzero(&m, sizeof(m));
	ls_cwd(v[0], m.path);
	if ((m.argc = n) == 1)
		return (ls_default((m.argv = v)[0]));
	m.param = ls_parameters(n, m.argv = v, &m.param.f);
	//	collect args, todo --
	//	colletc dirs
}

/*
**
*/

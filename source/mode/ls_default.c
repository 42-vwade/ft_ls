/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_default.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:51:47 by viwade            #+#    #+#             */
/*   Updated: 2020/01/26 16:24:00 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	set_cmp(t_param *p)
{
	(p->f.ss && ((p->cmp = p->f.r ? ls_rsizcmp : ls_sizcmp) || 1)) ||
	(p->f.t && ((p->cmp = p->f.r ? ls_rtcmp : ls_tcmp) || 1)) ||
	(p->cmp = p->f.r ? ls_rstrcmp : ls_strcmp);
}

int
	ls_default(t_param *p)
{
	set_cmp(p);
	return (ft_ls(p, p->cwd));
}

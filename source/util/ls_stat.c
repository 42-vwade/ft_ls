/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:42 by viwade            #+#    #+#             */
/*   Updated: 2020/01/26 15:28:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ls_stat(t_entry *e)
{
	if ((lstat(e->fullname, &e->stat) < 0) &&
			ft_printf("ft_ls: %s [%i]\n", strerror(errno), errno))
		exit(errno);
	e->links = e->stat.st_nlink;
	e->size = e->stat.st_size;
	e->pwd = getpwuid(e->stat.st_uid)[0];
	e->grp = getgrgid(e->stat.st_gid)[0];
	ft_strncpy(e->uname, e->pwd.pw_name, sizeof(e->uname) - 1);
	ft_strncpy(e->gname, e->grp.gr_name, sizeof(e->gname) - 1);
	return (1);
}

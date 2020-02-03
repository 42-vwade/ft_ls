/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2020/02/03 10:06:56 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCTS_H
# define FT_LS_STRUCTS_H
# include "ft_ls_includes.h"
# include "ft_ls_macros.h"

/*
**	TYPE DEFINITION
*/

typedef struct s_type	t_type;
typedef struct s_ls		t_ls;
typedef struct s_main	t_main;
typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;
typedef struct tm		t_time;
typedef struct s_node	t_node;
typedef struct s_entry	t_entry;
typedef struct s_flags	t_flags;
typedef struct s_parameters	t_param;

struct	s_type {
	char	t;
	char	owner[3];
	char	group[3];
	char	other[3];
	char	ext;
	char	null;
};

struct	s_entry
{
	t_type		t;
	short		links;
	char		uname[64];
	char		gname[64];
	long		size;
	time_t		mtime;
	char		ctime[13];
	char		cyear[5];
	char		name[NAME_MAX];
	char		link[PATH_MAX];
	char		name_ext[NAME_MAX + 4 + PATH_MAX];
	char		fullname[PATH_MAX];
	long		name_len;
	long		size_len;
	int			uid;
	int			gid;
	t_stat		stat;
	t_pwd		pwd;
	t_grp		grp;
	t_time		time;
	int			hidden;
	int			rev;
	int			dev_major;
	int			dev_minor;
	uint8_t		color;

};

struct	s_flags
{
	char	l;
	char	rr;
	char	a;
	char	r;
	char	t;
	char	u;
	char	f;
	char	g;
	char	d;
	char	gg;
	char	ss;
	char	n1;
};

struct	s_parameters
{
	int			n;
	char		*prgnm;
	char		*argv0;
	char		**v;
	t_flags		f;
	char		cwd[PATH_MAX + 1];
	int			(*cmp)(t_node*, t_node*);
};

struct	s_ls
{
	DIR				*dir;
	t_dirent		*e;
	t_entry			*cur;
	char			cwd[PATH_MAX + 1];
	uint32_t		maxlen;
	int				blocks;
	t_stat			buf;
	long			i;
	const t_flags	flags;
	t_node			*node;
	t_node			*list;
	t_node			*dirs;
	uint16_t		td[4];
	char			dev[2];
	int				(*cmp)(t_node*, t_node*);
};

struct	s_main
{
	int			argc;
	char		**argv;
	DIR			*dir;
	t_dirent	*e;
	t_stat		buf;
	t_node		*list;
	t_node		*node;
	long		i;
	t_flags		flags;
	t_param		param;
	t_node		*jobs;
	int			ret;
};

#endif

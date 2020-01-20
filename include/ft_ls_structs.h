/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 02:27:19 by viwade           ###   ########.fr       */
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
	char	null;
};

struct	s_entry
{
	t_type		t;
	short		links;
	char		uname[64];
	char		gname[64];
	long		size;
	char		ctime[13];
	char		name[NAME_MAX];
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
	t_dirent	*e;
};

struct	s_flags
{
	char	l: 1;
	char	rr: 1;
	char	a: 1;
	char	r: 1;
	char	t: 1;
	char	u: 1;
	char	f: 1;
	char	g: 1;
	char	d: 1;
	char	gg: 1;
};

struct	s_parameters
{
	int			n;
	char		**v;
	t_flags		f;
	char		*cwd;
};

struct	s_ls
{
	DIR			*dir;
	t_dirent	*e;
	char		*cwd;
	t_stat		buf;
	t_node		*list;
	t_node		*node;
	long		i;
	t_flags		flags;
	t_param		param;
	t_node		*dirs;
};

struct	s_main
{
	int			argc;
	char		**argv;
	char		cwd[PATH_MAX + 1];
	char		*prgnm;
	DIR			*dir;
	t_dirent	*e;
	t_stat		buf;
	t_node		*list;
	t_node		*node;
	long		i;
	t_flags		flags;
	t_param		param;
	t_node		*jobs;
};

#endif

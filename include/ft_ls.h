/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2020/01/26 16:10:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "ft_ls_includes.h"
# include "ft_ls_macros.h"
# include "ft_ls_structs.h"

int		ft_ls(const t_param *parameters, char *directory);
int		ls_paths(const t_param *parameters, t_node *jobs);
void	ls_lstdel(t_node *start);
int		ls_default(t_param *parameters);
void	ls_cwd(char path[PATH_MAX], char *argv0);
void	ls_endslash(char path[PATH_MAX]);
int		ls_stat(t_entry *entry);
int		ls_type(t_entry *entry);
t_entry	*ls_entry(t_entry *entry, t_ls *ls_index);
t_node	*ls_merge_sort(t_node *head, int (*cmp_function)(t_node*, t_node*));
int		ls_strcmp(t_node *left, t_node *right);
int		ls_tcmp(t_node *left, t_node *right);
int		ls_sizcmp(t_node *left, t_node *right);
int		ls_rstrcmp(t_node *left, t_node *right);
int		ls_rsizcmp(t_node *left, t_node *right);
int		ls_rtcmp(t_node *left, t_node *right);
t_node	*ls_collect_paths(t_param *parameters);
t_node	*ls_node_new(void *content);
void	ls_node_append(t_node **node, t_node *new);
char	*ls_strtrim(char const *s);
int		ls_dir(char path[PATH_MAX]);

#endif

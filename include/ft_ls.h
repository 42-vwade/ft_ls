/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:00:15 by viwade            #+#    #+#             */
/*   Updated: 2020/01/15 21:00:22 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "ft_ls_includes.h"
# include "ft_ls_macros.h"
# include "ft_ls_structs.h"

int		ft_ls(t_param parameters, char *directory);
int		ls_paths(t_param *parameters, t_node *jobs);
int		ls_default(char	*argv0);
void	ls_cwd(char *argv0, char path[PATH_MAX]);
t_node	*ls_merge_sort(t_node *head, int (*cmp_function)(t_node*, t_node*));
int		ls_strcmp(t_node *left, t_node *right);
int		ls_sizcmp(t_node *left, t_node *right);
t_node	*ls_collect_paths(char **argv);
t_node	*ls_node_new(void *content);
void	ls_node_append(t_node **node, t_node *new);

#endif

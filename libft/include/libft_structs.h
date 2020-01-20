/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:36:22 by viwade            #+#    #+#             */
/*   Updated: 2020/01/20 13:23:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H
# include <stdlib.h>

typedef struct s_list	t_list;
typedef struct s_num	t_num;
typedef struct s_str	t_str;
typedef struct s_128b	t_128b;
typedef struct s_node	t_node;
typedef struct s_stack	t_stack;
typedef struct s_queue	t_queue;
typedef struct s_v3d	t_v3d;

struct	s_v3d
{
	double_t	x;
	double_t	y;
	double_t	z;
};

struct	s_node
{
	void			*content;
	struct s_node	*next;
};

struct	s_queue
{
	struct s_node		*next;
	const unsigned char	free;
};

struct	s_stack
{
	struct s_node		*top;
	const unsigned char	free;
};

struct	s_list
{
	void			*content;
	struct s_list	*next;
	size_t			content_size;
};

struct	s_num
{
	size_t	length;
	char	*d;
};

struct	s_str
{
	char	*str;
	size_t	length;
	char	free:1;
};

struct	s_128b
{
	unsigned long long	a;
	unsigned long long	b;
};

#endif

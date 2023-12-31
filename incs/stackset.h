/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:32:17 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/02 08:57:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKSET_H
# define STACKSET_H

# include <stddef.h>

typedef struct s_stackset_vars
{
	size_t			size;
	size_t			head[2];
	size_t			len[2];
}					t_stackset_vars;

typedef struct s_stackset
{
	int				*stack;
	t_stackset_vars	vars;
}					t_stackset;

t_stackset			*new_stackset(int array[], size_t len);
void				del_stackset(t_stackset *s);
int					stackat(t_stackset *s, int stack, int i);
size_t				get_index_stack(t_stackset_vars *vars, int stack, int i);
size_t				get_index(t_stackset_vars *vars, int stack, int i);
void				print_stack(t_stackset *s);

#endif
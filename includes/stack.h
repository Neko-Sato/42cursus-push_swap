/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:20:54 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/28 07:02:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int				*value;
	struct s_stack	*head;
	struct s_stack	*tail;
}					t_stack;

void				print_stackset(t_stack stackset[2]);
void				init_stackset(t_stack stackset[2]);
void				finl_stackset(t_stack stackset[2]);

size_t				stack_len(t_stack *stack);
t_stack				*new_stack_element(void *value);
void				push_stack(t_stack *stack, t_stack *element);
t_stack				*pop_stack(t_stack *stack);

#endif
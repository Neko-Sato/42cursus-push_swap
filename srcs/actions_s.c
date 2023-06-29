/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:01:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <ft_printf.h>

void	do_sa(t_stackset *stackset)
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset->a);
	temp[1] = pop_stack(&stackset->a);
	push_stack(&stackset->a, temp[0]);
	push_stack(&stackset->a, temp[1]);
	ft_printf("sa\n");
}

void	do_sb(t_stackset *stackset)
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset->b);
	temp[1] = pop_stack(&stackset->b);
	push_stack(&stackset->b, temp[0]);
	push_stack(&stackset->b, temp[1]);
	ft_printf("sb\n");
}

void	do_ss(t_stackset *stackset)
{
	void	*temp[4];

	temp[0] = pop_stack(&stackset->a);
	temp[1] = pop_stack(&stackset->a);
	temp[2] = pop_stack(&stackset->b);
	temp[3] = pop_stack(&stackset->b);
	push_stack(&stackset->a, temp[0]);
	push_stack(&stackset->a, temp[1]);
	push_stack(&stackset->b, temp[2]);
	push_stack(&stackset->b, temp[3]);
	ft_printf("ss\n");
}

void do_s_(t_stackset *stackset, int slect)
{
	if(slect == 0b11)
		do_ss(stackset);
	else if (slect == 0b10)
		do_sa(stackset);
	else if (slect == 0b01)
		do_sb(stackset);
}

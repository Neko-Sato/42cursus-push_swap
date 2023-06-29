/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:00:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <ft_printf.h>

void	do_rra(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(&stackset->a);
	push_stack(stackset->a.head, temp);
	ft_printf("rra\n");
}

void	do_rrb(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(&stackset->b);
	push_stack(stackset->b.head, temp);
	ft_printf("rrb\n");
}

void	do_rrr(t_stackset *stackset)
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset->a);
	push_stack(stackset->a.head, temp[0]);
	temp[1] = pop_stack(&stackset->b);
	push_stack(stackset->b.head, temp[1]);
	ft_printf("rrr\n");
}

void do_rr_(t_stackset *stackset, int slect)
{
	if(slect == 0b11)
		do_rrr(stackset);
	else if (slect == 0b10)
		do_rra(stackset);
	else if (slect == 0b01)
		do_rrb(stackset);
}

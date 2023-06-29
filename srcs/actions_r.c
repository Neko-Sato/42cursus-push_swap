/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:00:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <ft_printf.h>

void	do_ra(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(stackset->a.head->head);
	push_stack(&stackset->a, temp);
	ft_printf("ra\n");
}

void	do_rb(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(stackset->b.head->head);
	push_stack(&stackset->b, temp);
	ft_printf("rb\n");
}

void	do_rr(t_stackset *stackset)
{
	void	*temp[2];

	temp[0] = pop_stack(stackset->a.head->head);
	push_stack(&stackset->a, temp[0]);
	temp[1] = pop_stack(stackset->b.head->head);
	push_stack(&stackset->b, temp[1]);
	ft_printf("rr\n");
}

void do_r_(t_stackset *stackset, int slect)
{
	if(slect == 0b11)
		do_rr(stackset);
	else if (slect == 0b10)
		do_ra(stackset);
	else if (slect == 0b01)
		do_rb(stackset);
}
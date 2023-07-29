/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 01:50:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "actions.h"
#include <ft_printf.h>

void	do_rra(t_stack stackset[2])
{
	void	*temp;

	temp = pop_stack(stackset[0].head->head);
	push_stack(&stackset[0], temp);
	ft_printf("rra\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_rrb(t_stack stackset[2])
{
	void	*temp;

	temp = pop_stack(stackset[1].head->head);
	push_stack(&stackset[1], temp);
	ft_printf("rrb\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_rrr(t_stack stackset[2])
{
	void	*temp[2];

	temp[0] = pop_stack(stackset[0].head->head);
	push_stack(&stackset[0], temp[0]);
	temp[1] = pop_stack(stackset[1].head->head);
	push_stack(&stackset[1], temp[1]);
	ft_printf("rrr\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_rr_(t_stack stackset[2], int slect)
{
	if (slect == 0b11)
		do_rrr(stackset);
	else if (slect == 0b10)
		do_rra(stackset);
	else if (slect == 0b01)
		do_rrb(stackset);
}

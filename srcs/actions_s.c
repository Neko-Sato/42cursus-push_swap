/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 01:50:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "actions.h"
#include <ft_printf.h>

void	do_sa(t_stack stackset[2])
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset[0]);
	temp[1] = pop_stack(&stackset[0]);
	push_stack(&stackset[0], temp[0]);
	push_stack(&stackset[0], temp[1]);
	ft_printf("sa\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_sb(t_stack stackset[2])
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset[1]);
	temp[1] = pop_stack(&stackset[1]);
	push_stack(&stackset[1], temp[0]);
	push_stack(&stackset[1], temp[1]);
	ft_printf("sb\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_ss(t_stack stackset[2])
{
	void	*temp[4];

	temp[0] = pop_stack(&stackset[0]);
	temp[1] = pop_stack(&stackset[0]);
	temp[2] = pop_stack(&stackset[1]);
	temp[3] = pop_stack(&stackset[1]);
	push_stack(&stackset[0], temp[0]);
	push_stack(&stackset[0], temp[1]);
	push_stack(&stackset[1], temp[2]);
	push_stack(&stackset[1], temp[3]);
	ft_printf("ss\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_s_(t_stack stackset[2], int slect)
{
	if (slect == 0b11)
		do_ss(stackset);
	else if (slect == 0b10)
		do_sa(stackset);
	else if (slect == 0b01)
		do_sb(stackset);
}

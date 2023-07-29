/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 01:48:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "actions.h"
#include <ft_printf.h>

void	do_pa(t_stack stackset[2])
{
	push_stack(&stackset[0], pop_stack(&stackset[1]));
	ft_printf("pa\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_pb(t_stack stackset[2])
{
	push_stack(&stackset[1], pop_stack(&stackset[0]));
	ft_printf("pb\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_pp(t_stack stackset[2])
{
	int	temp;

	temp = 0;
	temp |= (stackset[0].tail != &stackset[0]) << 1;
	temp |= (stackset[0].tail != &stackset[0]);
	if (temp == 0b11)
	{
		do_pa(stackset);
		do_sa(stackset);
		do_pb(stackset);
	}
	else if (temp == 0b10)
		do_pb(stackset);
	else if (temp == 0b01)
		do_pa(stackset);
}

void	do_p_(t_stack stackset[2], int slect)
{
	if (slect == 0b11)
		do_pp(stackset);
	else if (slect == 0b10)
		do_pa(stackset);
	else if (slect == 0b01)
		do_pb(stackset);
}

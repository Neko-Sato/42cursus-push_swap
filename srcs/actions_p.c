/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:00:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <ft_printf.h>

void	do_pa(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(&stackset->b);
	push_stack(&stackset->a, temp);
	ft_printf("pa\n");
}

void	do_pb(t_stackset *stackset)
{
	void	*temp;

	temp = pop_stack(&stackset->a);
	push_stack(&stackset->b, temp);
	ft_printf("pb\n");
}

void	do_pp(t_stackset *stackset)
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset->a);
	temp[1] = pop_stack(&stackset->b);
	push_stack(&stackset->b, temp[0]);
	push_stack(&stackset->a, temp[1]);
	ft_printf("pp\n");
}

void do_p_(t_stackset *stackset, int slect)
{
	if(slect == 0b11)
		do_pp(stackset);
	else if (slect == 0b10)
		do_pa(stackset);
	else if (slect == 0b01)
		do_pb(stackset);
}

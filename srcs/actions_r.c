/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:23:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 06:42:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "stack.h"
#include <ft_printf.h>

void	do_ra(t_stack stackset[2], int print)
{
	void	*temp;

	temp = pop_stack(&stackset[0]);
	push_stack(stackset[0].head, temp);
	if (print)
		ft_printf("ra\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_rb(t_stack stackset[2], int print)
{
	void	*temp;

	temp = pop_stack(&stackset[1]);
	push_stack(stackset[1].head, temp);
	if (print)
		ft_printf("rb\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_rr(t_stack stackset[2], int print)
{
	void	*temp[2];

	temp[0] = pop_stack(&stackset[0]);
	push_stack(stackset[0].head, temp[0]);
	temp[1] = pop_stack(&stackset[1]);
	push_stack(stackset[1].head, temp[1]);
	if (print)
		ft_printf("rr\n");
	if (STACK_PRINT)
		print_stackset(stackset);
}

void	do_r_(t_stack stackset[2], int slect, int print)
{
	if (slect == 0b11)
		do_rr(stackset, print);
	else if (slect == 0b10)
		do_ra(stackset, print);
	else if (slect == 0b01)
		do_rb(stackset, print);
}

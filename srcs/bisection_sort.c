/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:21:33 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 21:55:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	bisection_sort(t_stackset *stackset, int *target_a, int *target_b)
{
	t_stack	*stack;
	int		*target;
	int		pivot;

	if (!target_a == !target_b)
		return ;
	if (target_a)
	{
		stack = &stackset->a;
		target = target_a;
	}
	else
	{
		stack = &stackset->b;
		target = target_b;
	}
	pivot = get_pivot(stackset, target);
	// if()
	// 	mixed_sort(stackset, , );
	// else 		
	// 	mixed_sort(stackset, , );
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:49:30 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/30 14:28:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lt(int value, void *pivot)
{
	return (value < *(int *)pivot);
}

int	stack_gt(int value, void *pivot)
{
	return (value > *(int *)pivot);
}

void	init_sort(t_stackset *stackset)
{
	int		pivot;
	size_t	len;
	t_stack	*next_push;

	len = stack_len(&stackset->a);
	pivot = get_pivot(&stackset->a, len);
	while (len)
	{
		if (!next_push)
			next_push = stack_find(&stackset->a, len, stack_lt, &pivot);
		if (!next_push)
			break ;
		if (stackset->a.tail == next_push)
		{
			do_pb(stackset);
			next_push = NULL;
		}
		else
			do_rra(stackset);
		len--;
	}
}

void	finl_sort(t_stackset *stackset)
{
	while (&stackset->b == stackset->b.tail)
		do_pa(stackset);
}

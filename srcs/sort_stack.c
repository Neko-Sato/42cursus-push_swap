/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:49:30 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/29 18:52:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

int	stack_lt(int value, void *pivot)
{
	return (value < *(int *)pivot);
}

int	stack_gt(int value, void *pivot)
{
	return (value > *(int *)pivot);
}

int	init_sort(t_stack stackset[2])
{
	int		pivot;
	size_t	len;
	t_stack	*next_push;

	len = stack_len(&stackset[0]);
	pivot = get_pivot(&stackset[0], len, 0);
	next_push = NULL;
	while (len)
	{
		if (!next_push)
			next_push = stack_find(&stackset[0], len, (t_callable){stack_lt, &pivot});
		if (!next_push)
			break ;
		if (stackset[0].tail == next_push)
		{
			do_pb(stackset);
			next_push = NULL;
		}
		else
			do_ra(stackset);
		len--;
	}
	return (pivot);
}

void	finl_sort(t_stack stackset[2])
{
	while (&stackset[1] != stackset[1].tail)
		do_pa(stackset);
}
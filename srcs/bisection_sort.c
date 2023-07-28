/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:29:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/28 09:59:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	bisection_sort(t_stack stackset[2], int target[2])
{
	int		*sub_target;
	int		flag;
	int		record;

	flag = (target[0] <= 3) << 1 | (target[1] <= 3);
	if (flag & 0b10 == flag & 0b01)
		return ;
	sub_target = (int []){!(flag & 0b10) * target[0],
		!(flag & 0b01) * target[1]};
	record = 0;
	divide(stackset, flag, sub_target, &record);
	expand(stackset, flag, sub_target, &record);
	mixed_sort(stackset, sub_target);
}

static void	divide(t_stack stackset[2], int flag, int target[2], int *record)
{
	int		pivot;
	t_stack	*next_push;
	int		temp;

	pivot = get_pivot(&stackset[2 - flag], target[2 - flag], 0);
	next_push = NULL;
	while (1)
	{
		if (!next_push)
		{
			next_push = stack_find(&stackset[2 - flag], target[2 - flag],
					(t_callable){(void *[]){stack_gt, stack_lt}[2 - flag],
					&pivot});
			if (!next_push)
				break ;
		}
		temp = stackset[2 - flag].tail == next_push;
		if (temp)
			do_p_(stackset, 3 - flag);
		else
			do_r_(stackset, flag);
		target[2 - flag]--;
		*record += !temp;
		target[flag - 1] += temp;
	}
}

static void	expand(t_stack stackset[2], int flag, int target[2], int *record)
{
	while ((*record)--)
	{
		do_rr_(stackset, flag);
		target[2 - flag]++;
	}
}

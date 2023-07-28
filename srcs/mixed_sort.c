/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:53:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/28 14:36:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "actions.h"
#include <ft_printf.h>

static void	divide(t_stack stackset[2], int target[2], int pivot[2],
				int record[2]);
static void	expand_edge(t_stack stackset[2], int pivot[2], int target[2],
				int record[2]);
static void	expand_middle(t_stack stackset[2], int pivot[2], int target[2],
				int record[2]);

void	mixed_sort(t_stack stackset[2], int target[2])
{
	int	*pivot;
	int	*record;

	if (3 < target[0] && 3 < target[1])
	{
		record = (int []){0, 0};
		pivot = (int []){get_pivot(&stackset[0], target[0], 0),
			get_pivot(&stackset[1], target[1], 0)};
		divide(stackset, target, pivot, record);
		expand_edge(stackset, pivot, target, record);
		expand_middle(stackset, pivot, target, record);
	}
	else
	{
		polar_sort(stackset, target);
		bisection_sort(stackset, target);
	}
}

// stackBの方のみターゲットを読み切る
static void	move_back(t_stack stackset[2], t_stack *next_push[2], int target[2],
		int record[2])
{
	int	flag;

	flag = (stackset[0].tail == next_push[0])
		| (stackset[1].tail == next_push[1]) << 1;
	if (flag & 0b01)
		next_push[0] = NULL;
	if (flag & 0b10)
		next_push[1] = NULL;
	do_p_(stackset, flag);
	do_r_(stackset, flag);
	target[0] -= !!(flag & 0b01);
	target[1] -= !!(flag & 0b10);
	record[0] += !!(flag & 0b10);
	record[1] += !!(flag & 0b01);
	if (flag != 0b11)
	{
		flag = !!next_push[0] << 1
			| (((~flag & 0b01) && !!next_push[1])
				|| (!next_push[1] && (0 < target[1])));
		do_r_(stackset, flag);
		target[0] -= !!(flag & 0b10);
		target[1] -= !!(flag & 0b01);
		record[0] += !!(flag & 0b10);
		record[1] += !!(flag & 0b01);
	}
}

static void	divide(t_stack stackset[2], int target[2], int pivot[2],
		int record[2])
{
	int		completed;
	t_stack	**next_push;

	completed = 0;
	next_push = (t_stack *[]){NULL, NULL};
	while (1)
	{
		if (!next_push[0] && (~completed & 0b10))
		{
			next_push[0] = stack_find(&stackset[0], target[0],
					(t_callable){stack_lt, &pivot[0]});
			if (!next_push[0])
				completed |= 0b10;
		}
		if (!next_push[1] && (~completed & 0b01))
		{
			next_push[1] = stack_find(&stackset[1], target[1],
					(t_callable){stack_lt, &pivot[1]});
			if (!next_push[1])
				completed |= 0b01;
		}
		if ((completed & 0b10) && !target[1])
			break ;
		move_back(stackset, next_push, target, record);
	}
}

static void	expand_edge(t_stack stackset[2], int pivot[2], int target[2],
		int record[2])
{
	int	temp;

	while (record[0]--)
	{
		do_rra(stackset);
		temp = pivot[0] > *stackset[0].tail->value;
		if (temp)
			do_pb(stackset);
		target[temp]++;
	}
	mixed_sort(stackset, target);
	while (1)
	{
		temp = (*stackset[0].tail->value < pivot[0])
			- (*stackset[1].tail->value > pivot[0]);
		if (!temp)
			break ;
		target[temp > 0]--;
		do_pb(stackset);
		target[temp < 0]++;
	}
}

static void	expand_middle(t_stack stackset[2], int pivot[2], int target[2],
		int record[2])
{
	int	temp;
	int	*sub_target;

	sub_target = (int []){0, 0};
	while (record[1]--)
	{
		do_rrb(stackset);
		temp = pivot[1] < *stackset[1].tail->value;
		if (temp)
			do_pa(stackset);
		sub_target[!temp]++;
	}
	mixed_sort(stackset, sub_target);
	target[0] += sub_target[0];
	target[1] += sub_target[1];
}

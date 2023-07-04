/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:53:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/04 00:27:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <ft_printf.h>

static void	divide(t_stackset *stackset, int target[2], int pivot[2],
				int record[2]);
static void	expand_edge(t_stackset *stackset, int pivot[2], int target[2],
				int record[2]);
static void	expand_middle(t_stackset *stackset, int pivot[2], int target[2],
				int record[2]);

void	mixed_sort(t_stackset *stackset, int target[2])
{
	int	*pivot;
	int	*record;

	if (polar_sort(stackset, target))
		return ;
	pivot = (int[]){
		get_pivot(&stackset->a, target[0]),
		get_pivot(&stackset->b, target[1])};
	record = (int[]){0, 0};
	print_stackset(stackset);
	divide(stackset, target, pivot, record);
	print_stackset(stackset);
	expand_edge(stackset, pivot, target, record);
	expand_middle(stackset, pivot, target, record);
}

static void	move_back(t_stackset *stackset, t_stack *next_push[2],
		int target[2], int record[2])
{
	int	flag;

	flag = (stackset->a.tail == next_push[0]) | (stackset->b.tail == next_push[1]) << 1;
	if (flag & 0b01)
		next_push[0] = NULL;
	if (flag & 0b10)
		next_push[1] = NULL;
	do_p_(stackset, flag);
	do_rr_(stackset, flag);
	target[0] -= !!(flag & 0b01);
	target[1] -= !!(flag & 0b10);
	record[0] += !!(flag & 0b10);
	record[1] += !!(flag & 0b01);
	if (flag != 0b11)
	{
		flag = !!next_push[0] << 1 | !!next_push[1];
		do_rr_(stackset, flag);
		target[0] -= !!(flag & 0b10);
		target[1] -= !!(flag & 0b01);
		record[0] += !!(flag & 0b10);
		record[1] += !!(flag & 0b01);
	}
}

static void	divide(t_stackset *stackset, int target[2], int pivot[2],
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
			next_push[0] = stack_find(&stackset->a, target[0], stack_lt,
					&pivot[0]);
			if (!next_push[0])
				completed |= 0b10;
		}
		if (!next_push[1] && (~completed & 0b01))
		{
			next_push[1] = stack_find(&stackset->b, target[1], stack_lt,
					&pivot[1]);
			if (!next_push[1])
				completed |= 0b01;
		}
		if (completed == 0b11)
			break ;
		move_back(stackset, next_push, target, record);
	}
}

static void	expand_edge(t_stackset *stackset, int pivot[2], int target[2],
		int record[2])
{
	int	temp;

	while (record[0]--)
	{
		do_ra(stackset);
		temp = pivot[0] > *stackset->a.tail->value;
		if (temp)
			do_pb(stackset);
		target[temp]++;
	}
	mixed_sort(stackset, target);
	while (target[0]--)
	{
		do_pb(stackset);
		target[1]++;
	}
}

static void	expand_middle(t_stackset *stackset, int pivot[2], int target[2],
		int record[2])
{
	int	temp;
	int	*sub_target;

	sub_target = (int[]){0, 0};
	while (record[1]--)
	{
		do_rb(stackset);
		temp = pivot[1] < *stackset->b.tail->value;
		if (temp)
			do_pa(stackset);
		sub_target[!temp]++;
	}
	mixed_sort(stackset, sub_target);
	target[0] += sub_target[0];
	target[1] += sub_target[1];
}

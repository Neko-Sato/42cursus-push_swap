/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:29:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 04:41:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "push_swap.h"
#include "stack.h"
#include <ft_printf.h>

static int	divide(t_stack stackset[2], int flag, int target[2], int *record);
static void	expand(t_stack stackset[2], int flag, int target[2], int *record);

void	bisection_sort(t_stack stackset[2], int target[2])
{
	int	*sub_target;
	int	pivot;
	int	flag;
	int	record;

	flag = (3 < target[0]) << 1 | (3 < target[1]);
	if ((flag & 0b10) == (flag & 0b01))
		return ;
	sub_target = (int []){!!(flag & 0b10) * target[0],
		!!(flag & 0b01) * target[1]};
	record = 0;
	pivot = divide(stackset, flag, sub_target, &record);
	expand(stackset, flag, sub_target, &record);
	mixed_sort(stackset, sub_target, pivot);
	while (sub_target[flag - 1]--)
	{
		do_p_(stackset, flag);
		sub_target[2 - flag]++;
	}
	target[2 - flag] = sub_target[2 - flag];
}

static void	move(t_stack stackset[2], int flag, int *vars[],
	t_stack **next_push)
{
	int	temp;

	vars[0][2 - flag]--;
	temp = stackset[2 - flag].tail == *next_push;
	if (temp)
	{
		do_p_(stackset, 3 - flag);
		*next_push = NULL;
	}
	else
		do_r_(stackset, flag);
	vars[0][flag - 1] += temp;
	*vars[1] += !temp;
}

static int	divide(t_stack stackset[2], int flag, int target[2], int *record)
{
	int		pivot;
	t_stack	*next_push;

	pivot = get_pivot(&stackset[2 - flag], target[2 - flag], 0);
	next_push = NULL;
	while (1)
	{
		if (!next_push)
		{
			next_push = stack_find(&stackset[2 - flag], target[2 - flag],
					(t_callable){(void *[]){stack_lt, stack_gt}[2 - flag],
					&pivot});
			if (!next_push)
				break ;
		}
		move(stackset, flag, (int *[]){target, record}, &next_push);
	}
	return (pivot);
}

static void	expand(t_stack stackset[2], int flag, int target[2], int *record)
{
	while ((*record)--)
	{
		do_rr_(stackset, flag);
		target[2 - flag]++;
	}
}

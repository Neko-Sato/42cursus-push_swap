/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:31:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 03:10:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "actions.h"

static int	check_do_s(t_stack stackset[2], int flag);
static void	update_flag(t_stack stackset[2], int target[2], int *flag);

void	polar_sort(t_stack stackset[2], int target[2])
{
	int	flag;

	flag = (target[0] <= 3) << 1 | (target[1] <= 3);
	update_flag(stackset, target, &flag);
	do_s_(stackset, check_do_s(stackset, flag));
	update_flag(stackset, target, &flag);
	do_r_(stackset, flag);
	do_s_(stackset, flag);
	do_rr_(stackset, flag);
	update_flag(stackset, target, &flag);
	do_s_(stackset, check_do_s(stackset, flag));
}

static int	check_do_s(t_stack stackset[2], int flag)
{
	int	temp;

	temp = 0;
	if (flag & 0b10)
		temp |= (*(int *)stackset[0].tail->value
				> *(int *)stackset[0].tail->tail->value) << 1;
	if (flag & 0b01)
		temp |= (*(int *)stackset[1].tail->value
				< *(int *)stackset[1].tail->tail->value);
	return (flag & temp);
}

static void	update_flag(t_stack stackset[2], int target[2], int *flag)
{
	int	temp;

	temp = 0;
	temp |= ((*flag & 0b10) && !is_sorted(&stackset[0], target[0], 1)) << 1;
	temp |= ((*flag & 0b01) && !is_sorted(&stackset[1], target[1], 0));
	*flag &= temp;
}

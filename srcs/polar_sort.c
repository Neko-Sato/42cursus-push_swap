/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:31:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/04 08:20:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

static void	need_sort(t_stackset *stackset, int target[2], int *flag);

//	Sort when the sort target is 3 or less.
int	polar_sort(t_stackset *stackset, int target[2])
{
	int	flag;

	flag = (1 < target[0] && target[0] <= 3) << 1 | (1 < target[1]
			&& target[1] <= 3);
	if (!flag)
		return (0);
	need_sort(stackset, target, &flag);
	do_s_(stackset, flag);
	need_sort(stackset, target, &flag);
	do_rr_(stackset, flag);
	do_s_(stackset, flag);
	do_r_(stackset, flag);
	need_sort(stackset, target, &flag);
	do_s_(stackset, flag);
	if ((1 < target[0] && target[0] <= 3) ^ (1 < target[1] && target[1] <= 3))
		bisection_sort(stackset, , );
	return (1);
}

static void	need_sort(t_stackset *stackset, int target[2], int *flag)
{
	int	temp;

	temp = 0;
	temp |= (*flag & 0b10 && !is_sorted(&stackset->a, target[0], 1)) << 1;
	temp |= (*flag & 0b01 && !is_sorted(&stackset->b, target[1], 0));
	*flag &= temp;
}

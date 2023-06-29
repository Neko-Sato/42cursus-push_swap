/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:31:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 21:41:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

static void	check(int *flag, int *target_a, int *target_b);
static void	update_target(t_stackset *stackset, int *a, int *b, int flag);

//	Sort when the sort target is 3 or less.
void	polar_sort(t_stackset *stackset, int *target_a, int *target_b)
{
	int	flag;

	while (1)
	{
		check(&flag, target_a, target_b);
		update_target(stackset, target_a, target_b, flag);
		check(&flag, target_a, target_b);
		if (!flag)
			return ;
		do_s_(stackset, flag);
		check(&flag, target_a, target_b);
		update_target(stackset, target_a, target_b, flag);
		check(&flag, target_a, target_b);
		if (!flag)
			return ;
		do_rr_(stackset, flag);
		do_s_(stackset, flag);
		do_r_(stackset, flag);
	}
}

static void	check(int *required_sort, int *target_a, int *target_b)
{
	*required_sort = 0;
	*required_sort |= (0 < *target_a && *target_a <= 3) << 1;
	*required_sort |= (0 < *target_b && *target_b <= 3);
}

static void	update_target(t_stackset *stackset, int *target_a, int *target_b,
		int required_sort)
{
	if (required_sort & 0b10 && is_sorted(&stackset->a, *target_a, 1))
		*target_a = 0;
	if (required_sort & 0b01 && is_sorted(&stackset->b, *target_b, 0))
		*target_a = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:08:10 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 03:36:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include "actions.h"
#include "sort.h"

void	quick_sort_stacka(t_stackset *s, size_t len)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stacka(s, len));
	count = 0;
	pivot = get_pivot(s, 0, len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 0, 0) < pivot)
		{
			do_action(s, pb, 1);
			count++;
		}
		else
			do_actions(s, (t_actions []){pb, rb}, 2, 1);
	}
	quick_sort_stackb_top(s, count);
	quick_sort_stackb_bottom(s, len - count);
}

void	quick_sort_stackb_top(t_stackset *s, size_t len)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stackb_top(s, len));
	count = 0;
	pivot = get_pivot(s, 1, len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 1, 0) < pivot)
		{
			do_action(s, pa, 1);
			count++;
		}
		else
			do_action(s, rb, 1);
	}
	quick_sort_stacka(s, count);
	quick_sort_stackb_bottom(s, len - count);
}

void	quick_sort_stackb_bottom(t_stackset *s, size_t len)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stackb_bottom(s, len));
	count = 0;
	pivot = get_pivot(s, 1, -(int)len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 1, -1) < pivot)
		{
			do_actions(s, (t_actions []){rrb, pa}, 2, 1);
			count++;
		}
		else
			do_action(s, rrb, 1);
	}
	quick_sort_stacka(s, count);
	quick_sort_stackb_top(s, len - count);
}

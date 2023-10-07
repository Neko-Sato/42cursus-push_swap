/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:08:10 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 09:17:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include "actions.h"
#include "sort.h"

void	quick_sort_stacka(t_stackset *s, size_t len, void *buff)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stacka(s, len, buff));
	count = 0;
	pivot = get_pivot(s, 0, len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 0, 0) < pivot)
		{
			do_action(s, pb, buff);
			count++;
		}
		else
			do_actions(s, (t_actions []){pb, rb}, 2, buff);
	}
	quick_sort_stackb_top(s, count, buff);
	quick_sort_stackb_bottom(s, len - count, buff);
}

void	quick_sort_stackb_top(t_stackset *s, size_t len, void *buff)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stackb_top(s, len, buff));
	count = 0;
	pivot = get_pivot(s, 1, len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 1, 0) < pivot)
		{
			do_action(s, pa, buff);
			count++;
		}
		else
			do_action(s, rb, buff);
	}
	quick_sort_stacka(s, count, buff);
	quick_sort_stackb_bottom(s, len - count, buff);
}

void	quick_sort_stackb_bottom(t_stackset *s, size_t len, void *buff)
{
	int		pivot;
	size_t	n;
	size_t	count;

	if (len <= 12)
		return (insert_sort_stackb_bottom(s, len, buff));
	count = 0;
	pivot = get_pivot(s, 1, -(int)len);
	n = 0;
	while (n++ < len)
	{
		if (stackat(s, 1, -1) < pivot)
		{
			do_actions(s, (t_actions []){rrb, pa}, 2, buff);
			count++;
		}
		else
			do_action(s, rrb, buff);
	}
	quick_sort_stacka(s, count, buff);
	quick_sort_stackb_top(s, len - count, buff);
}

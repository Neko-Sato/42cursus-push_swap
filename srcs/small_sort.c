/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:44:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 02:37:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "sort.h"
#include "stackset.h"

static void	smaller_move(t_stackset *s, size_t len, void *buff);
static void	three_sort(t_stackset *s, void *buff);

void	small_sort(t_stackset *s, size_t len, void *buff)
{
	smaller_move(s, len, buff);
	three_sort(s, buff);
	while (s->vars.len[1])
		do_action(s, pa, buff);
}

static void	smaller_move(t_stackset *s, size_t len, void *buff)
{
	int	next;

	if (3 < len)
	{
		while (1)
		{
			next = get_next_put_lt(s, 0, s->vars.len[0], len - 3);
			if (next < 0)
				break ;
			while (stackat(s, 0, 0) != next)
				do_action(s, ra, buff);
			do_action(s, pb, buff);
		}
	}
}

static void	three_sort(t_stackset *s, void *buff)
{
	if (2 < s->vars.len[0])
	{
		if (stackat(s, 0, 0) > stackat(s, 0, 1)
			&& stackat(s, 0, 0) > stackat(s, 0, 2))
			do_action(s, ra, buff);
		else if (stackat(s, 0, 1) > stackat(s, 0, 0)
			&& stackat(s, 0, 1) > stackat(s, 0, 2))
			do_action(s, rra, buff);
	}
	if (2 < s->vars.len[1])
	{
		if (stackat(s, 1, 0) < stackat(s, 1, 1)
			&& stackat(s, 1, 0) < stackat(s, 1, 2))
			do_action(s, rb, buff);
		else if (stackat(s, 1, 1) < stackat(s, 1, 0)
			&& stackat(s, 1, 1) < stackat(s, 1, 2))
			do_action(s, rrb, buff);
	}
	if (!is_sorted(s, 0, s->vars.len[0]))
		do_action(s, sa, buff);
	if (!is_sorted(s, 1, s->vars.len[1]))
		do_action(s, sb, buff);
}

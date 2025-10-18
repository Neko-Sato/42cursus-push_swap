/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:54:56 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 04:42:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "optimization.h"

static int	_is_sorted(t_stacks *s, t_stackname name, int reverse)
{
	size_t	i;
	int		pre;
	int		cur;

	i = 0;
	if (i < stacks_len(s, name))
	{
		pre = stacks_at(s, name, i++);
		while (i < stacks_len(s, name))
		{
			cur = stacks_at(s, name, i++);
			if ((!reverse && pre > cur) || (reverse && pre < cur))
				return (0);
			pre = cur;
		}
	}
	return (1);
}

static inline void	_sort(t_stacks *s, t_action_buffer *buf)
{
	if (2 < stacks_len(s, STACK_A))
	{
		if (stacks_at(s, STACK_A, 0) > stacks_at(s, STACK_A, 1)
			&& stacks_at(s, STACK_A, 0) > stacks_at(s, STACK_A, 2))
			(void)(stacks_ra(s), action_buffer_put(buf, ACT_RA));
		else if (stacks_at(s, STACK_A, 1) > stacks_at(s, STACK_A, 0)
			&& stacks_at(s, STACK_A, 1) > stacks_at(s, STACK_A, 2))
			(void)(stacks_rra(s), action_buffer_put(buf, ACT_RRA));
	}
	if (2 < stacks_len(s, STACK_B))
	{
		if (stacks_at(s, STACK_B, 0) < stacks_at(s, STACK_B, 1)
			&& stacks_at(s, STACK_B, 0) < stacks_at(s, STACK_B, 2))
			(void)(stacks_rb(s), action_buffer_put(buf, ACT_RB));
		else if (stacks_at(s, STACK_B, 1) < stacks_at(s, STACK_B, 0)
			&& stacks_at(s, STACK_B, 1) < stacks_at(s, STACK_B, 2))
			(void)(stacks_rrb(s), action_buffer_put(buf, ACT_RRB));
	}
	if (!_is_sorted(s, STACK_A, 0))
		(void)(stacks_sa(s), action_buffer_put(buf, ACT_SA));
	if (!_is_sorted(s, STACK_B, 1))
		(void)(stacks_sb(s), action_buffer_put(buf, ACT_SB));
}

int	small_sort(t_stacks *s, t_action_buffer *buf)
{
	int	pivot;

	pivot = stacks_len(s, STACK_A) - 3;
	while (3 < stacks_len(s, STACK_A))
	{
		while (pivot <= stacks_at(s, STACK_A, 0))
			(void)(stacks_ra(s), action_buffer_put(buf, ACT_RA));
		(void)(stacks_pb(s), action_buffer_put(buf, ACT_PB));
	}
	_sort(s, buf);
	while (stacks_len(s, STACK_B))
		(void)(stacks_pa(s), action_buffer_put(buf, ACT_PA));
	return (0);
}

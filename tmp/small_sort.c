/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:54:56 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/27 15:49:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "push_swap.h"

static int	_is_sorted(t_stacks *s, t_stackname name)
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
			if (elemless(cur, pre, name))
				return (0);
			pre = cur;
		}
	}
	return (1);
}

static inline void	_sort(t_stacks *s, t_optimizer *buf)
{
	t_stackname	i;

	i = 0;
	while (i < _STACK_SIZE)
	{
		if (2 < stacks_len(s, i))
		{
			if (elemless(stacks_at(s, i, 1), stacks_at(s, i, 0), i)
				&& elemless(stacks_at(s, i, 2), stacks_at(s, i, 0), i))
				do_action(s, buf, _ACT_R_ | (1 << i));
			else if (elemless(stacks_at(s, i, 0), stacks_at(s, i, 1), i)
				&& elemless(stacks_at(s, i, 2), stacks_at(s, i, 1), i))
				do_action(s, buf, _ACT_RR_ | (1 << i));
		}
		i++;
	}
	i = 0;
	while (i < _STACK_SIZE)
	{
		if (!_is_sorted(s, i))
			do_action(s, buf, _ACT_S_ | (1 << i));
		i++;
	}
}

int	small_sort(t_stacks *s, t_optimizer *buf)
{
	int	pivot;

	pivot = stacks_len(s, STACK_A) - 3;
	while (3 < stacks_len(s, STACK_A))
	{
		while (pivot <= stacks_at(s, STACK_A, 0))
			do_action(s, buf, ACT_RA);
		do_action(s, buf, ACT_PB);
	}
	_sort(s, buf);
	while (stacks_len(s, STACK_B))
		do_action(s, buf, ACT_PA);
	return (0);
}

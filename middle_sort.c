/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:08:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 05:13:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimization.h"
#include "stacks.h"
#include <assert.h>

static int	_sort(t_stacks *s, t_action_buffer *buf, t_stackname name,
		size_t len)
{
	static void (*const	_p[2])(t_stacks *) = {stacks_pb, stacks_pa};
	static void (*const	_r[2])(t_stacks *) = {stacks_ra, stacks_rb};
	static void (*const	_rr[2])(t_stacks *) = {stacks_rra, stacks_rrb};
	int					cnt[2];
	int					pivot;

	while (cnt[0] + cnt[1] < len)
	{
		if (stacks_at(s, name, 0) < pivot)
		{
			g_actions[ACT_NONE].fun(s)
			//pする
			cnt[0]++;
		}
		else
		{
			//rする
			cnt[1]++;
		}
	}
	if (_sort(s, buf, !name, cnt[0]) || _sort(s, buf, name, cnt[1]))
		return (1);
	while (cnt[1])
	{
		//rrして戻す
		cnt[1]--;
	}
	while (cnt[0])
	{
		//pした分戻す
		cnt[0]--;
	}
	return (0);
}

int	middle_sort(t_stacks *s, t_action_buffer *buf)
{
	return (_sort(s, buf, STACK_A, stacks_len(s, STACK_A)));
}

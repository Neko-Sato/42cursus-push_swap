/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:17:12 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/18 13:01:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	_action_rr(t_stacks *s, t_stackname name)
{
	int	tmp;

	if (1 < s->_len[name])
	{
		tmp = s->_data[_stacks_index(s, name, -1)];
		s->_head[name] = _stacks_buffer_index(s, name, -1);
		s->_data[_stacks_buffer_index(s, name, 0)] = tmp;
	}
}

void	stacks_rra(t_stacks *s)
{
	_action_rr(s, STACK_A);
}

void	stacks_rrb(t_stacks *s)
{
	_action_rr(s, STACK_B);
}

void	stacks_rrr(t_stacks *s)
{
	_action_rr(s, STACK_A);
	_action_rr(s, STACK_B);
}

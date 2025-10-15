/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 04:13:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	_action_p(t_stacks *s, t_stackname name)
{
	int	tmp;

	if (s->_len[!name])
	{
		tmp = s->_data[_stacks_index(s, !name, 0)];
		s->_head[!name] = _stacks_buffer_index(s, !name, 1);
		s->_len[!name]--;
		if (s->_len[name])
			s->_head[name] = _stacks_buffer_index(s, name, -1);
		s->_len[name]++;
		s->_data[_stacks_index(s, name, 0)] = tmp;
	}
}

void	stacks_pa(t_stacks *s)
{
	_action_p(s, STACK_A);
}

void	stacks_pb(t_stacks *s)
{
	_action_p(s, STACK_B);
}

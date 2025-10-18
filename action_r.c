/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:17:12 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/17 15:22:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	_action_r(t_stacks *s, t_stackname name)
{
	int	tmp;

	if (1 < s->_len[name])
	{
		tmp = s->_data[_stacks_buffer_index(s, name, 0)];
		s->_head[name] = _stacks_buffer_index(s, name, 1);
		s->_data[_stacks_index(s, name, -1)] = tmp;
	}
}

void	stacks_ra(t_stacks *s)
{
	_action_r(s, STACK_A);
}

void	stacks_rb(t_stacks *s)
{
	_action_r(s, STACK_B);
}

void	stacks_rr(t_stacks *s)
{
	_action_r(s, STACK_A);
	_action_r(s, STACK_B);
}

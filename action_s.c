/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:16:09 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 04:07:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	_action_s(t_stacks *s, t_stackname name)
{
	int	*n[2];
	int	tmp;

	if (1 < s->_len[name])
	{
		n[0] = &s->_data[_stacks_buffer_index(s, name, 0)];
		n[1] = &s->_data[_stacks_buffer_index(s, name, 1)];
		tmp = *n[0];
		*n[0] = *n[1];
		*n[1] = tmp;
	}
}

void	stacks_sa(t_stacks *s)
{
	_action_s(s, STACK_A);
}

void	stacks_sb(t_stacks *s)
{
	_action_s(s, STACK_B);
}

void	stacks_ss(t_stacks *s)
{
	_action_s(s, STACK_A);
	_action_s(s, STACK_B);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/15 18:24:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	_action_p(t_stacks *s, t_stackname name)
{
	int	tmp;

	if (s->len[!name])
	{
		tmp = s->data[stacks_index(s, !name, 0)];
		s->head[!name] = _stacks_buffer_index(s, !name, 1);
		s->len[!name]--;
		if (s->len[name])
			s->head[name] = _stacks_buffer_index(s, name, -1);
		s->len[name]++;
		s->data[stacks_index(s, name, 0)] = tmp;
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

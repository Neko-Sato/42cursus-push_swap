/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/27 16:21:27 by hshimizu         ###   ########.fr       */
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

static void	_action_p(t_stacks *s, t_stackname name)
{
	int	tmp;

	if (s->_len[!name])
	{
		tmp = s->_data[_stacks_buffer_index(s, !name, 0)];
		s->_head[!name] = _stacks_buffer_index(s, !name, 1);
		s->_len[!name]--;
		if (s->_len[name])
			s->_head[name] = _stacks_buffer_index(s, name, -1);
		s->_len[name]++;
		s->_data[_stacks_buffer_index(s, name, 0)] = tmp;
	}
}

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

void	stacks_binary(t_stacks *s, void *data, size_t n)
{
	static void (*const	funs[])(t_stacks *, t_stackname) = {
		_action_s, _action_p, _action_r, _action_rr};
	unsigned char		*binary;
	unsigned int		i;

	binary = data;
	while (n)
	{
		i = 0;
		while (i < _STACK_SIZE)
		{
			if (*binary & (1 << i))
				funs[*binary >> 2](s, i);
			i++;
		}
		n--;
	}
}

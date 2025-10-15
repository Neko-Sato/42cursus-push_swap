/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:43:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 04:05:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <libft.h>

int	stacks_init(t_stacks *stacks, int *array, size_t size)
{
	int	*data;

	data = malloc(sizeof(int) * size * 2);
	if (!data)
		return (-1);
	stacks->_data = data;
	ft_memcpy(data, array, sizeof(int) * size);
	stacks->_size = size;
	stacks->_head[STACK_A] = 0;
	stacks->_len[STACK_A] = size;
	stacks->_head[STACK_B] = 0;
	stacks->_len[STACK_B] = 0;
	return (0);
}

void	stacks_destroy(t_stacks *stacks)
{
	free(stacks->_data);
}

size_t	_stacks_buffer_index(const t_stacks *stacks, t_stackname name, long p)
{
	p += stacks->_head[name];
	p %= stacks->_size;
	if (p < 0)
		p += stacks->_size;
	return (stacks->_size * name + p);
}

size_t	_stacks_index(const t_stacks *stacks, t_stackname name, long p)
{
	p %= stacks->_len[name];
	if (p < 0)
		p += stacks->_len[name];
	return (_stacks_buffer_index(stacks, name, p));
}

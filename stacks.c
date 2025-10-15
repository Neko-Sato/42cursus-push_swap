/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:43:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 03:22:39 by hshimizu         ###   ########.fr       */
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
	stacks->data = data;
	ft_memcpy(data, array, sizeof(int) * size);
	stacks->size = size;
	stacks->head[STACK_A] = 0;
	stacks->len[STACK_A] = size;
	stacks->head[STACK_B] = 0;
	stacks->len[STACK_B] = 0;
	return (0);
}

void	stacks_destroy(t_stacks *stacks)
{
	free(stacks->data);
}

size_t	_stacks_buffer_index(const t_stacks *stacks, t_stackname name, long p)
{
	p += stacks->head[name];
	p %= stacks->size;
	if (p < 0)
		p += stacks->size;
	return (stacks->size * name + p);
}

size_t	stacks_index(const t_stacks *stacks, t_stackname name, long p)
{
	p %= stacks->len[name];
	if (p < 0)
		p += stacks->len[name];
	return (_stacks_buffer_index(stacks, name, p));
}

int	stacks_check(const t_stacks *stacks)
{
	size_t	i;
	int		pre;

	if (stacks->len[STACK_B])
		return (0);
	if (stacks->len[STACK_A])
	{
		i = 0;
		pre = stacks->data[stacks_index(stacks, STACK_A, i++)];
		while (i < stacks->len[STACK_A])
			if (pre > stacks->data[stacks_index(stacks, STACK_A, i++)])
				return (0);
	}
	return (1);
}

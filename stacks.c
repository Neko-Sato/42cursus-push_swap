/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:43:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/18 18:18:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <libft.h>

const t_action_entry	g_actions[_ACT_SIZE] = {
[ACT_NONE] = {"", NULL},
[ACT_SA] = {"sa", stacks_sa},
[ACT_SB] = {"sb", stacks_sb},
[ACT_SS] = {"ss", stacks_ss},
[ACT_PA] = {"pa", stacks_pa},
[ACT_PB] = {"pb", stacks_pb},
[ACT_RA] = {"ra", stacks_ra},
[ACT_RB] = {"rb", stacks_rb},
[ACT_RR] = {"rr", stacks_rr},
[ACT_RRA] = {"rra", stacks_rra},
[ACT_RRB] = {"rrb", stacks_rrb},
[ACT_RRR] = {"rrr", stacks_rrr},
};

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
	p %= (long)stacks->_size;
	p += stacks->_size;
	p %= (long)stacks->_size;
	return (stacks->_size * name + p);
}

size_t	_stacks_index(const t_stacks *stacks, t_stackname name, long p)
{
	p %= (long)stacks->_len[name];
	p += stacks->_len[name];
	p %= (long)stacks->_len[name];
	return (_stacks_buffer_index(stacks, name, p));
}

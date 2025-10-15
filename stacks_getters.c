/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 04:05:59 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 04:13:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

size_t	stacks_len(const t_stacks *stacks, t_stackname name)
{
	return (stacks->_len[name]);
}

int	stacks_at(const t_stacks *stacks, t_stackname name, long p)
{
	return (stacks->_data[_stacks_index(stacks, name, p)]);
}

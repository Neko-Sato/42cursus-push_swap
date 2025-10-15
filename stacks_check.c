/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:11:18 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 04:08:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	stacks_check(const t_stacks *s)
{
	size_t	i;
	int		pre;

	if (stacks_len(s, STACK_B))
		return (0);
	if (stacks_len(s, STACK_A))
	{
		i = 0;
		pre = stacks_at(s, STACK_A, i++);
		while (i < stacks_len(s, STACK_A))
			if (pre > stacks_at(s, STACK_A, i++))
				return (0);
	}
	return (1);
}

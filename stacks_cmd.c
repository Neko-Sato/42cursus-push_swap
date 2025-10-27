/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:01:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/27 16:22:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	stacks_cmd(t_stacks *stacks, const char *cmd)
{
	static const char *const	names[] = {
	[ACT_NONE] = "",
	[ACT_SA] = "sa", [ACT_SB] = "sb", [ACT_SS] = "ss",
	[ACT_PA] = "pa", [ACT_PB] = "pb",
	[ACT_RA] = "ra", [ACT_RB] = "rb", [ACT_RR] = "rr",
	[ACT_RRA] = "rra", [ACT_RRB] = "rrb", [ACT_RRR] = "rrr",
	};
	size_t						i;

	if (!*cmd)
		return (0);
	i = 0;
	while (i < _ACT_SIZE)
	{
		if (names[i] && !ft_strcmp(names[i], cmd))
			return (stacks_binary(stacks, &i, 1), 0);
		i++;
	}
	return (1);
}

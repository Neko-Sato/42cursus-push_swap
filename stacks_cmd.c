/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:01:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 17:02:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	stacks_cmd(t_stacks *stacks, const char *cmd)
{
	static const t_action_entry	entries[] = {
	{"pa", stacks_pa}, {"pb", stacks_pb},
	{"sa", stacks_sa}, {"sb", stacks_sb}, {"ss", stacks_ss},
	{"ra", stacks_ra}, {"rb", stacks_rb}, {"rr", stacks_rr},
	{"rra", stacks_rra}, {"rrb", stacks_rrb}, {"rrr", stacks_rrr},
	};
	static const size_t			entries_size
		= sizeof(entries) / sizeof(*entries);
	size_t						i;

	if (!*cmd)
		return (0);
	i = 0;
	while (i < entries_size)
	{
		if (!ft_strcmp(entries[i].cmd, cmd))
			return (entries[i].fun(stacks), 0);
		i++;
	}
	return (1);
}

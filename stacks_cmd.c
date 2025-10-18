/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:01:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/18 10:35:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	stacks_cmd(t_stacks *stacks, const char *cmd)
{
	size_t						i;

	if (!*cmd)
		return (0);
	i = 0;
	while (i < _ACT_SIZE)
	{
		if (!ft_strcmp(g_actions[i].cmd, cmd))
			return (g_actions[i].fun(stacks), 0);
		i++;
	}
	return (1);
}

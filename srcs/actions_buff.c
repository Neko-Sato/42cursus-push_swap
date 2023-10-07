/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:55:13 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 11:57:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void	set_action_buff(t_actions action, void *buff)
{
	if (ft_xlstappend(buff, sizeof(t_actions), &action))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	put_action_buff(void *buff)
{
	t_actions	action;
	char		*str;

	while (!ft_xlstpop(buff, sizeof(t_actions), 0, &action))
	{
		str = astion2str(action);
		if (str)
			ft_putendl_fd(str, STDOUT_FILENO);
	}
}

static int	get_4actions(t_actions actions[4], size_t i, void *buff);

void	optimized_action_buff(void *buff)
{
	t_actions	actions[4];
	size_t		i;

	i = 0;
	while (1)
	{
		if (get_4actions(actions, i, buff))
			break ;
		if (optimized_action(actions))
		{
			if (!actions[3])
				ft_xlstpop(buff, sizeof(t_actions), i + 3, NULL);
			if (!actions[2])
				ft_xlstpop(buff, sizeof(t_actions), i + 2, NULL);
			if (!actions[1])
				ft_xlstpop(buff, sizeof(t_actions), i + 1, NULL);
			if (!actions[0])
				ft_xlstpop(buff, sizeof(t_actions), i, NULL);
			else
				ft_xlstset(*(void **)buff, sizeof(t_actions), i, &actions[0]);
			i = (4 < i) * (i - 4);
		}
		else
			i++;
	}
}

static int	get_4actions(t_actions actions[4], size_t i, void *buff)
{
	if (ft_xlstat(*(void **)buff, sizeof(t_actions), i, &actions[0])
		|| ft_xlstat(*(void **)buff, sizeof(t_actions), i + 1, &actions[1]))
		return (1);
	if (ft_xlstat(*(void **)buff, sizeof(t_actions), i + 2, &actions[2]))
		actions[2] = error;
	if (actions[2] == error || ft_xlstat(*(void **)buff, sizeof(t_actions), i
			+ 3, &actions[3]))
		actions[3] = error;
	return (0);
}

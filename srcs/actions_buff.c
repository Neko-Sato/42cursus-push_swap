/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:55:13 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/04 22:05:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static void	*g_buff;

void	set_action_buff(t_actions action)
{
	if (ft_xlstappend(&g_buff, sizeof(t_actions), &action))
	{
		ft_putendl_fd("error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	put_action_buff(void)
{
	t_actions	action;
	char		*str;

	while (!ft_xlstpop(&g_buff, sizeof(t_actions), 0, &action))
	{
		str = astion2str(action);
		if (str)
			ft_putendl_fd(str, STDOUT_FILENO);
	}
}

void	optimized_action_buff(void)
{
	t_actions	peri;
	t_actions	post;
	size_t		i;

	i = 0;
	while (1)
	{
		if (ft_xlstat(g_buff, sizeof(t_actions), i, &peri)
			|| ft_xlstat(g_buff, sizeof(t_actions), i + 1, &post))
			return ;
		if (optimized_action(&peri, &post))
		{
			ft_xlstpop(&g_buff, sizeof(t_actions), i + 1, NULL);
			if (peri != noaction)
				ft_xlstset(g_buff, sizeof(t_actions), i, &peri);
			else
				ft_xlstpop(&g_buff, sizeof(t_actions), i--, NULL);
		}
		else
			i++;
	}
}

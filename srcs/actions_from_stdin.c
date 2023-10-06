/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_from_stdin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:38:29 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 04:09:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <actions.h>
#include <errno.h>
#include <libft.h>
#include <stackset.h>
#include <stdlib.h>
#include <unistd.h>

static int	loop(t_bufferio *f, t_stackset *s, int *has_error);

int	actions_from_stdin(t_stackset *s)
{
	t_bufferio	*f;
	int			has_error;

	has_error = 0;
	f = ft_bufferionew(STDIN_FILENO, 0);
	if (!f)
		return (-1);
	while (1)
		if (loop(f, s, &has_error))
			break ;
	ft_bufferiodel(f, 0);
	return (has_error || errno);
}

static int	loop(t_bufferio *f, t_stackset *s, int *has_error)
{
	char		*cmd;
	char		*split;
	t_actions	action;

	cmd = ft_readline(f);
	if (!cmd)
		return (1);
	split = ft_strchr(cmd, '\n');
	if (!split)
	{
		*has_error = 1;
		free(cmd);
		return (1);
	}
	*split = '\0';
	action = str2action(cmd);
	if (action == error)
	{
		*has_error = 1;
		free(cmd);
		return (1);
	}
	do_action(s, action, 0);
	free(cmd);
	return (0);
}

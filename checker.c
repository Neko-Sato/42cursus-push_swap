/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 03:38:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

static inline int	_internal3(t_stacks *stacks, const char *cmd)
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

static inline int	_internal2(t_stacks *stacks, t_istream *is)
{
	char	*line;
	size_t	linesize;
	ssize_t	nread;

	line = NULL;
	linesize = 0;
	while (1)
	{
		nread = ft_istream_getline(&line, &linesize, is);
		if (nread == -1)
			break ;
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if (_internal3(stacks, line))
			return (free(line), 1);
	}
	return (free(line), ft_istream_error(is));
}

static inline int	_internal(t_stacks *stacks)
{
	int			tmp;
	int			fd;
	t_istream	is;

	fd = STDIN_FILENO;
	if (ft_istream_init(&is, ft__read_fd, &fd))
		return (1);
	tmp = _internal2(stacks, &is);
	ft_istream_destroy(&is);
	return (tmp);
}

int	checker(int *arr, size_t size)
{
	int			tmp;
	t_stacks	stacks;

	if (stacks_init(&stacks, arr, size))
		return (1);
	tmp = _internal(&stacks);
	if (!tmp)
		ft_printf("%s\n", (const char *[]){"KO", "OK"}[stacks_check(&stacks)]);
	stacks_destroy(&stacks);
	return (tmp);
}

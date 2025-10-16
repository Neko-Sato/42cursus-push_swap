/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_istream.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:06:55 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 17:08:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <libft.h>
#include <stdlib.h>

int	stacks_istream(t_stacks *stacks, t_istream *is)
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
		if (stacks_cmd(stacks, line))
			return (free(line), 1);
	}
	return (free(line), ft_istream_error(is));
}

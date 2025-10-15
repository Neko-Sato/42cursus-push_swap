/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:11:18 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 04:05:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <ft_printf.h>
#include <unistd.h>

static inline void	_print(const t_stacks *s, t_stackname name, int fd)
{
	size_t	i;

	i = 0;
	if (i < stacks_len(s, name))
	{
		while (1)
		{
			ft_dprintf(fd, "%d", stacks_at(s, name, i++));
			if (i >= stacks_len(s, name))
				break ;
			ft_dprintf(fd, ", ");
		}
	}
	ft_dprintf(fd, "\n");
}

void	stacks_print(const t_stacks *s, int fd)
{
	ft_dprintf(fd, "a: ");
	_print(s, STACK_A, fd);
	ft_dprintf(fd, "b: ");
	_print(s, STACK_B, fd);
}

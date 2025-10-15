/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:11:18 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/15 20:18:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <ft_printf.h>
#include <unistd.h>

static inline void	_print(const t_stacks *s, t_stackname name)
{
	size_t	i;

	i = 0;
	if (i < s->len[name])
	{
		while (1)
		{
			ft_dprintf(STDERR_FILENO, "%d", s->data[stacks_index(s, name,
					i++)]);
			if (i >= s->len[name])
				break ;
			ft_dprintf(STDERR_FILENO, ", ");
		}
	}
	ft_dprintf(STDERR_FILENO, "\n");
}

void	stacks_print(const t_stacks *s)
{
	ft_dprintf(STDERR_FILENO, "a: ");
	_print(s, STACK_A);
	ft_dprintf(STDERR_FILENO, "b: ");
	_print(s, STACK_B);
}

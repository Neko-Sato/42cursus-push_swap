/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/02 07:52:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include <libft.h>

static void	action_p(t_stackset *s, int stack)
{
	int	temp;

	if (s->vars.len[!stack])
	{
		temp = s->stack[get_index(&s->vars, !stack, 0)];
		s->vars.head[!stack] = get_index_stack(&s->vars, !stack, 1);
		s->vars.len[!stack]--;
		if (s->vars.len[stack])
			s->vars.head[stack] = get_index_stack(&s->vars, stack, -1);
		s->vars.len[stack]++;
		s->stack[get_index(&s->vars, stack, 0)] = temp;
	}
}

void	do_pa(t_stackset *s, int print)
{
	action_p(s, 0);
	if (print)
		ft_putendl_fd("pa", 1);
}

void	do_pb(t_stackset *s, int print)
{
	action_p(s, 1);
	if (print)
		ft_putendl_fd("pb", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:17:12 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 19:33:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"

void	action_rr(t_stackset *s, int stack)
{
	int	temp;

	if (1 < s->vars.len[stack])
	{
		temp = s->stack[get_index(&s->vars, stack, -1)];
		s->vars.head[stack] = get_index_stack(&s->vars, stack, -1);
		s->stack[get_index(&s->vars, stack, 0)] = temp;
	}
}

void	do_rra(t_stackset *s)
{
	action_rr(s, 0);
}

void	do_rrb(t_stackset *s)
{
	action_rr(s, 1);
}

void	do_rrr(t_stackset *s)
{
	action_rr(s, 0);
	action_rr(s, 1);
}

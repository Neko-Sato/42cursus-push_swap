/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:17:12 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/04 21:55:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include <libft.h>

static void	action_r(t_stackset *s, int stack)
{
	int	temp;

	if (1 < s->vars.len[stack])
	{
		temp = s->stack[get_index(&s->vars, stack, 0)];
		s->vars.head[stack] = get_index_stack(&s->vars, stack, 1);
		s->stack[get_index(&s->vars, stack, -1)] = temp;
	}
}

void	do_ra(t_stackset *s)
{
	action_r(s, 0);
}

void	do_rb(t_stackset *s)
{
	action_r(s, 1);
}

void	do_rr(t_stackset *s)
{
	action_r(s, 0);
	action_r(s, 1);
}

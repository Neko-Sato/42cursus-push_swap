/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:16:09 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/04 21:56:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include <libft.h>

static void	action_s(t_stackset *s, int stack)
{
	int	*n[2];
	int	temp;

	if (1 < s->vars.len[stack])
	{
		n[0] = &s->stack[get_index(&s->vars, stack, 0)];
		n[1] = &s->stack[get_index(&s->vars, stack, 1)];
		temp = *n[0];
		*n[0] = *n[1];
		*n[1] = temp;
	}
}

void	do_sa(t_stackset *s)
{
	action_s(s, 0);
}

void	do_sb(t_stackset *s)
{
	action_s(s, 1);
}

void	do_ss(t_stackset *s)
{
	action_s(s, 0);
	action_s(s, 1);
}

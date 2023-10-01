/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/02 07:58:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <stddef.h>

void	do_action(t_stackset *s, t_actions action, int print)
{
	(t_do_action []){NULL, NULL, NULL, NULL, NULL, do_pa, do_pb, NULL, NULL,
		do_sa, do_sb, do_ss, NULL, do_ra, do_rb, do_rr, NULL, do_rra, do_rrb,
		do_rrr}[action](s, print);
}

void	do_actions(t_stackset *s, t_actions *actions, size_t len, int print)
{
	size_t	i;

	i = 0;
	while (i < len)
		do_action(s, actions[i++], print);
}

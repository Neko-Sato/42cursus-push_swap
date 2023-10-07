/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:15:24 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 09:07:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <libft.h>

t_actions	str2action(char *str)
{
	if (!ft_strcmp("pa", str))
		return (pa);
	else if (!ft_strcmp("pb", str))
		return (pb);
	else if (!ft_strcmp("sa", str))
		return (sa);
	else if (!ft_strcmp("sb", str))
		return (sb);
	else if (!ft_strcmp("ss", str))
		return (ss);
	else if (!ft_strcmp("ra", str))
		return (ra);
	else if (!ft_strcmp("rb", str))
		return (rb);
	else if (!ft_strcmp("rr", str))
		return (rr);
	else if (!ft_strcmp("rra", str))
		return (rra);
	else if (!ft_strcmp("rrb", str))
		return (rrb);
	else if (!ft_strcmp("rrr", str))
		return (rrr);
	else
		return (error);
}

char	*astion2str(t_actions action)
{
	return ((char *[]){NULL, NULL, NULL, NULL, NULL, "pa", "pb", NULL, NULL,
		"sa", "sb", "ss", NULL, "ra", "rb", "rr", NULL, "rra", "rrb",
		"rrr"}[action]);
}

void	do_action(t_stackset *s, t_actions action, void *buff)
{
	(t_do_action []){NULL, NULL, NULL, NULL, NULL, do_pa, do_pb, NULL, NULL,
		do_sa, do_sb, do_ss, NULL, do_ra, do_rb, do_rr, NULL, do_rra, do_rrb,
		do_rrr}[action](s);
	if (buff)
		set_action_buff(action, buff);
}

void	do_actions(t_stackset *s, t_actions *actions, size_t len, void *buff)
{
	size_t	i;

	i = 0;
	while (i < len)
		do_action(s, actions[i++], buff);
}

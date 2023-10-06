/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:35:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 03:19:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	to_noaction(t_actions *peri, t_actions *post);
static int	to_one_action(t_actions *peri, t_actions *post);
static int	to_double_action(t_actions *peri, t_actions *post);
static int	to_s_action(t_actions *peri, t_actions *post, t_actions *post2,
				t_actions *post3);

int	optimized_action(t_actions actions[4])
{
	if (actions[0] <= 0 || actions[1] <= 0)
		return (0);
	if (to_noaction(&actions[0], &actions[1]))
		return (1);
	else if (to_double_action(&actions[0], &actions[1]))
		return (1);
	else if (to_one_action(&actions[0], &actions[1]))
		return (1);
	if (actions[2] <= 0 || actions[3] <= 0)
		return (0);
	if (to_s_action(&actions[0], &actions[1], &actions[2], &actions[3]))
		return (1);
	return (0);
}

static int	to_noaction(t_actions *peri, t_actions *post)
{
	if ((*peri == pa && *post == pb) || (*peri == pb && *post == pa)
		|| (*peri == sa && *post == sa) || (*peri == sb && *post == sb)
		|| (*peri == ss && *post == ss) || (*peri == ra && *post == rra)
		|| (*peri == rra && *post == ra) || (*peri == rb && *post == rrb)
		|| (*peri == rrb && *post == rb) || (*peri == rr && *post == rrr)
		|| (*peri == rrr && *post == rr))
		*peri = noaction;
	else
		return (0);
	*post = noaction;
	return (1);
}

static int	to_one_action(t_actions *peri, t_actions *post)
{
	if ((*peri == ss && *post == sb) || (*peri == sb && *post == ss))
		*peri = sa;
	else if ((*peri == ss && *post == sa) || (*peri == sa && *post == ss))
		*peri = sb;
	else if ((*peri == rr && *post == rrb) || (*peri == rrb && *post == rr))
		*peri = ra;
	else if ((*peri == rr && *post == rra) || (*peri == rra && *post == rr))
		*peri = rb;
	else if ((*peri == rrr && *post == rb) || (*peri == rb && *post == rrr))
		*peri = rra;
	else if ((*peri == rrr && *post == ra) || (*peri == ra && *post == rrr))
		*peri = rrb;
	else
		return (0);
	*post = noaction;
	return (1);
}

static int	to_double_action(t_actions *peri, t_actions *post)
{
	if ((*peri == sa && *post == sb) || (*peri == sb && *post == sa))
		*peri = ss;
	else if ((*peri == ra && *post == rb) || (*peri == rb && *post == ra))
		*peri = rr;
	else if ((*peri == rra && *post == rrb) || (*peri == rrb && *post == rra))
		*peri = rrr;
	else
		return (0);
	*post = noaction;
	return (1);
}

static int	to_s_action(t_actions *peri, t_actions *post, t_actions *post2,
		t_actions *post3)
{
	if ((*peri == pb && *post == ra && *post2 == pa && *post3 == rra)
		|| (*peri == ra && *post == pb && *post2 == rra && *post3 == pa))
	{
		*peri = sa;
		*post = noaction;
		*post2 = noaction;
		*post3 = noaction;
	}
	else if ((*peri == pa && *post == rb && *post2 == pb && *post3 == rrb)
		|| (*peri == rb && *post == pa && *post2 == rrb && *post3 == pb))
	{
		*peri = sa;
		*post = noaction;
		*post2 = noaction;
		*post3 = noaction;
	}
	else
		return (0);
	return (1);
}

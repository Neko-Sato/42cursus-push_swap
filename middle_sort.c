/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:08:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/22 00:12:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"



static inline int	_median(t_stacks *s, t_stackname name, size_t n, int *res)
{
	int		*tmp;
	size_t	i;

	tmp = malloc(sizeof(int) * n);
	if (!tmp)
		return (1);
	i = 0;
	while (i < n)
	{
		tmp[i] = stacks_at(s, name, i);
		i++;
	}
	ft_qsort(&(t_qsort){tmp, n, sizeof(int), (int (*)(const void *,
				const void *))ft_intcmp});
	*res = tmp[n / 2];
	free(tmp);
	return (0);
}

static inline void	_edge(
	t_stacks *s, t_optimizer *buf, t_stackname name, size_t len)
{
	if (0 == MAX)
		s
	if (1 == MAX)
		rr s r
	else (0 != MIN)
		s
}

static inline int	_normal(
	t_stacks *s, t_optimizer *buf, t_stackname name, size_t len)
{
	static const t_action	acts[][2] = {
	{ACT_PB, ACT_PA}, {ACT_RA, ACT_RB}, {ACT_RRA, ACT_RRB}
	};
	int						cnt[2];
	int						pivot;

	if (_median(s, name, len, &pivot))
		return (1);
	ft_memset(cnt, 0, sizeof(cnt));
	while (len)
	{
		if (stacks_at(s, name, 0) < pivot) //nameにわせて反転
			(void)(cnt[0]++, do_action(s, buf, acts[0][name]));
		else
			(void)(cnt[1]++, do_action(s, buf, acts[1][name]));
		len--;
	}
	while (cnt[1])
		(void)(cnt[1]--, do_action(s, buf, acts[2][name]));
	if (_sort(s, buf, !name, cnt[0]) || _sort(s, buf, name, cnt[1]))
		return (1);
	while (cnt[0])
		(void)(cnt[0]--, do_action(s, buf, acts[0][!name]));
	return (0);
}

static int	_sort(t_stacks *s, t_optimizer *buf, t_stackname name, size_t len)
{
	if (3 < len)
		return (_normal(s, buf, name, len));
	_edge(s, buf, name, len);
	return (0);
}

int	middle_sort(t_stacks *s, t_optimizer *buf)
{
	return (_sort(s, buf, STACK_A, stacks_len(s, STACK_A)));
}

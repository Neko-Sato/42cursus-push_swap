/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:08:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/25 00:18:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "push_swap.h"
#include "stacks.h"

static int	_median(t_stacks *s, t_stackname name, long len, int *res)
{
	size_t	n;
	int		*tmp;
	size_t	i;
	long	start;

	if (len < 0)
		n = -len;
	else
		n = len;
	tmp = malloc(sizeof(int) * n);
	if (!tmp)
		return (1);
	if (len < 0)
		start = len;
	else
		start = 0;
	i = 0;
	while (i < n)
		tmp[i++] = stacks_at(s, name, start++);
	ft_qsort(&(t_qsort){tmp, n, sizeof(int), (int (*)(const void *,
				const void *))ft_intcmp});
	*res = tmp[n / 2];
	free(tmp);
	return (0);
}

int	quick_sort_stack_b(t_stacks *s, t_optimizer *buf, long n);

int	quick_sort_stack_a(t_stacks *s, t_optimizer *buf, long n)
{
	int		pivot;
	long	cnt[2];

	if (-1 <= n && n <= 1)
	{
		if (n == -1)
			do_action(s, buf, ACT_RRA);
		return (0);
	}
	if (_median(s, STACK_A, n, &pivot))
		return (1);
	ft_memset(cnt, 0, sizeof(cnt));
	while (n)
	{
		if (n < 0)
			do_action(s, buf, ACT_RRA);
		if (pivot < stacks_at(s, STACK_A, 0))
		{
			if (n < 0)
				cnt[1]++;
			else
				(void)(cnt[1]--, do_action(s, buf, ACT_RA));
		}
		else
			(void)(cnt[0]++, do_action(s, buf, ACT_PB));
		n += (int []){-1, 1}[n < 0];
	}
	return (quick_sort_stack_a(s, buf, cnt[1])
		|| quick_sort_stack_b(s, buf, cnt[0]));
}

int	quick_sort_stack_b(t_stacks *s, t_optimizer *buf, long n)
{
	int		pivot;
	long	cnt[2];

	if (-1 <= n && n <= 1)
	{
		if (n == -1)
			do_action(s, buf, ACT_RRB);
		if (-1 == n || n == 1)
			do_action(s, buf, ACT_PA);
		return (0);
	}
	if (_median(s, STACK_B, n, &pivot))
		return (1);
	ft_memset(cnt, 0, sizeof(cnt));
	while (n)
	{
		if (n < 0)
			do_action(s, buf, ACT_RRB);
		if (pivot < stacks_at(s, STACK_B, 0))
			(void)(cnt[1]++, do_action(s, buf, ACT_PA));
		else
		{
			if (n < 0)
				cnt[0]++;
			else
				(void)(cnt[0]--, do_action(s, buf, ACT_RB));	
		}
		n += (int []){-1, 1}[n < 0];
	}
	return (quick_sort_stack_a(s, buf, cnt[1])
		|| quick_sort_stack_b(s, buf, cnt[0]));
}


int	middle_sort(t_stacks *s, t_optimizer *buf)
{
	return (_quick_sort_a(s, buf, stacks_len(s, STACK_A)));
}

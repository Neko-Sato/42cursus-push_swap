/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:49:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 09:15:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "sort.h"
#include "stackset.h"
#include <libft.h>

static size_t	send_less(t_stackset *s, size_t len, int head, void *buff);
static int		get_smallest(t_stackset *s, size_t len);

void	insert_sort_stacka(t_stackset *s, size_t len, void *buff)
{
	int		head;
	size_t	count;

	if (len < 1)
		return ;
	head = stackat(s, 0, 0);
	count = send_less(s, len, head, buff);
	insert_sort_stackb_top(s, count, buff);
	do_action(s, ra, buff);
	return (insert_sort_stacka(s, len - (count + 1), buff));
}

void	insert_sort_stackb_top(t_stackset *s, size_t len, void *buff)
{
	int		smallest;
	size_t	n;
	size_t	count;

	if (len)
	{
		smallest = get_smallest(s, len);
		n = 0;
		while (n++ < len)
		{
			count = 0;
			while (stackat(s, 1, 0) != smallest)
			{
				do_action(s, rb, buff);
				count++;
			}
			do_actions(s, (t_actions[]){pa, ra}, 2, buff);
			while (count--)
				do_action(s, rrb, buff);
			smallest++;
		}
	}
}

void	insert_sort_stackb_bottom(t_stackset *s, size_t len, void *buff)
{
	size_t	n;

	n = len;
	while (n--)
		do_action(s, rrb, buff);
	insert_sort_stackb_top(s, len, buff);
}

static size_t	send_less(t_stackset *s, size_t len, int head, void *buff)
{
	int		next;
	size_t	count;
	size_t	n;

	count = 0;
	n = 0;
	while (1)
	{
		next = get_next_put_lt(s, 0, len - (n + count), head);
		if (next < 0)
			break ;
		while (stackat(s, 0, 0) != next)
		{
			do_action(s, ra, buff);
			n++;
		}
		do_action(s, pb, buff);
		count++;
		if (1 < count && stackat(s, 1, 0) > stackat(s, 1, 1))
			do_action(s, sb, buff);
	}
	while (n--)
		do_action(s, rra, buff);
	return (count);
}

static int	get_smallest(t_stackset *s, size_t len)
{
	int		ret;
	size_t	n;

	n = 0;
	ret = stackat(s, 1, n++);
	while (n < len)
		ret = ft_min(ret, stackat(s, 1, n++));
	return (ret);
}

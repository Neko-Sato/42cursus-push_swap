/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:42:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 02:38:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "sort.h"
#include "stackset.h"
#include <errno.h>
#include <libft.h>
#include <unistd.h>

int	push_swap(int *array, size_t len)
{
	t_stackset	*s;
	void		*actions_buff;

	actions_buff = NULL;
	s = new_stackset(array, len);
	if (!s)
		return (-1);
	if (!is_sorted(s, 0, len))
	{
		if (len <= 6)
			small_sort(s, len, &actions_buff);
		else
			quick_sort_stacka(s, len, &actions_buff);
		optimized_action_buff(&actions_buff);
		put_action_buff(&actions_buff);
	}
	del_stackset(s);
	return (0);
}

int	checker(int *array, size_t len)
{
	t_stackset	*s;

	s = new_stackset(array, len);
	if (!s)
		return (-1);
	if (actions_from_stdin(s))
	{
		del_stackset(s);
		return (-1);
	}
	if (!s->vars.len[1] && is_sorted(s, 0, len))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	del_stackset(s);
	return (0);
}

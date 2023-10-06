/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:42:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 20:18:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "sort.h"
#include "stackset.h"
#include "utils.h"
#include <errno.h>
#include <libft.h>
#include <unistd.h>

int	push_swap(int *array, size_t len)
{
	t_stackset	*s;

	s = new_stackset(array, len);
	if (!s)
		return (-1);
	if (!is_sorted(s, len))
	{
		if (len <= 3)
			three_sort(s, len);
		else
			quick_sort_stacka(s, len);
		optimized_action_buff();
		put_action_buff();
	}
	del_stackset(s);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:44:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 09:12:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include "actions.h"
#include "sort.h"

void	three_sort(t_stackset *s, size_t len, void *buff)
{
	if (2 < len)
	{
		if (stackat(s, 0, 0) == 2)
			do_action(s, ra, buff);
		else if (stackat(s, 0, 1) == 2)
			do_action(s, rra, buff);
		if (is_sorted(s, len))
			return ;
	}
	do_action(s, sa, buff);
}

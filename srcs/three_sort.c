/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:44:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 20:17:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include "actions.h"
#include "utils.h"

void	three_sort(t_stackset *s, size_t len)
{
	if (2 < len)
	{
		if (stackat(s, 0, 0) == 2)
			do_action(s, ra, 1);
		else if (stackat(s, 0, 1) == 2)
			do_action(s, rra, 1);
		if (is_sorted(s, len))
			return ;
	}
	do_action(s, sa, 1);
}

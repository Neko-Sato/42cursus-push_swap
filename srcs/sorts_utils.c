/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:15:46 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:01:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack, int target, int descending)
{
	int		ret;
	t_stack	*temp;

	ret = 1;
	temp = stack->tail;
	while (ret && target-- && temp->tail != stack)
	{
		if (descending)
			ret &= *(int *)temp->value < *(int *)temp->tail->value;
		else
			ret &= *(int *)temp->value > *(int *)temp->tail->value;
		temp = temp->tail;
	}
	return (ret);
}


// int		get_pivot(t_stack *stack, int target)
// {
	
// }
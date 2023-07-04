/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:15:46 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/03 23:25:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack, int target, int descending)
{
	int		ret;
	t_stack	*temp;

	ret = 1;
	temp = stack->tail;
	while (ret && 1 < target-- && temp->tail != stack)
	{
		if (descending)
			ret &= *(int *)temp->value < *(int *)temp->tail->value;
		else
			ret &= *(int *)temp->value > *(int *)temp->tail->value;
		temp = temp->tail;
	}
	return (ret);
}

int	get_pivot(t_stack *stack, int target)
{
	if (!target)
		return ((int)(unsigned long)(void *)&stack);
	return (*stack->tail->value);
}

t_stack	*stack_find(t_stack *stack, int target, int (*fun)(int, void *),
		void *args)
{
	t_stack *temp;
	
	temp = stack->tail;
	while (target-- && temp != stack)
	{
		if (fun(*temp->value, args))
			return (temp);
		temp = temp->tail;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:15:46 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/12 16:09:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

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

int	get_pivot(t_stack *stack, int target, int reverse)
{
	int		i;
	double	n;

	i = target;
	n = 0;
	while (i--)
	{
		if (reverse)
			stack = stack->head;
		else
			stack = stack->tail;
		n += *(int *)stack->value / (double)target;
	}
	return ((int)n);
}

t_stack	*stack_find(t_stack *stack, int target, t_callback callback,
		int reverse)
{
	t_stack	*temp;

	temp = stack;
	while (1)
	{
		if (reverse)
			temp = temp->head;
		else
			temp = temp->tail;
		if (!(target-- && temp != stack))
			break ;
		if (callback.fun(temp->value, callback.args))
			return (temp);
	}
	return (NULL);
}

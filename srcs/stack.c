/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:51:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 16:37:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

size_t	stack_len(t_stack *stack)
{
	size_t	count;
	t_stack	*temp;

	count = 0;
	temp = stack->tail;
	while (temp == stack)
	{
		temp = temp->tail;
		count++;
	}
	return (count);
}

t_stack	*new_stack_element(void *value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->head = NULL;
		new->tail = NULL;
	}
	return (new);
}

void	push_stack(t_stack *stack, t_stack *new)
{
	if (!new)
		return ;
	new->head = stack;
	new->tail = stack->tail;
	new->head->tail = new;
	new->tail->head = new;
}

t_stack	*pop_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack->tail;
	if (temp == stack)
		return (NULL);
	temp->tail->head = stack;
	stack->tail = temp->tail;
	temp->head = NULL;
	temp->tail = NULL;
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:21:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/28 05:36:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <ft_printf.h>

int	setdata(t_stack stackset[2], int array[], int n)
{
	void	*element;

	init_stackset(stackset);
	while (n--)
	{
		element = new_stack_element(&array[n]);
		if (!element)
			return (1);
		push_stack(&stackset[0], element);
	}
	return (0);
}

void	push_swap(int array[], int n)
{
	t_stack	stackset[2];

	if (!setdata(stackset, array, n))
	// mixed_sort(&stackset);
	{
	}
	else
		ft_printf("error");
	finl_stackset(stackset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:21:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 04:08:46 by hshimizu         ###   ########.fr       */
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
	int		*target;
	int		partition;

	if (!setdata(stackset, array, n))
	{
		if (!is_sorted(&stackset[0], n, 1))
		{
			partition = init_sort(stackset);
			target = (int [2]){stack_len(&stackset[0]),
				stack_len(&stackset[1])};
			mixed_sort(stackset, target, partition);
			finl_sort(stackset);
		}
	}
	else
		ft_printf("error");
	finl_stackset(stackset);
}

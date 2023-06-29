/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:21:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 21:08:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <ft_printf.h>

int	setdata(t_stackset *stackset, int array[], int n)
{
	void	*element;

	init_stackset(stackset);
	while (n--)
	{
		element = new_stack_element(&array[n]);
		if (!element)
			return (1);
		push_stack(&stackset->a, element);
	}
	return (0);
}

void	sort_finalize(t_stackset *stackset)
{
	while (&stackset->b == stackset->b.tail)
		do_pa(stackset);
}

void	push_swap(int array[], int n)
{
	t_stackset	stackset;

	if (!setdata(&stackset, array, n))
	// mixed_sort(&stackset);
	{
	}
	else
		ft_printf("error");
	fin_stackset(&stackset);
}

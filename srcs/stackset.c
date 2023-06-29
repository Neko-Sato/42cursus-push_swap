/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:28 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 19:28:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stdlib.h"
#include <ft_printf.h>

void	init_stackset(t_stackset *stackset)
{
	stackset->a.value = NULL;
	stackset->a.head = &stackset->a;
	stackset->a.tail = &stackset->a;
	stackset->b.value = NULL;
	stackset->b.head = &stackset->b;
	stackset->b.tail = &stackset->b;
}

void	fin_stackset(t_stackset *stackset)
{
	void	*temp;

	while (1)
	{
		temp = pop_stack(&stackset->a);
		if (!temp)
			break ;
		free(temp);
	}
	while (1)
	{
		temp = pop_stack(&stackset->b);
		if (!temp)
			break ;
		free(temp);
	}
}

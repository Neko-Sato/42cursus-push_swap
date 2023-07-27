/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:28 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/28 05:31:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stdlib.h"
#include <ft_printf.h>

void	print_stackset(t_stack stackset[2])
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < 2)
	{
		ft_printf("%c: ", 'a' + i);
		temp = stackset[i].tail;
		while (&stackset[i] != temp)
		{
			ft_printf("%2d, ", *temp->value);
			temp = temp->tail;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void	init_stackset(t_stack stackset[2])
{
	int	i;

	i = 0;
	while (i < 2)
	{
		stackset[i].value = NULL;
		stackset[i].head = &stackset[i];
		stackset[i].tail = &stackset[i];
		i++;
	}
}

void	finl_stackset(t_stack stackset[2])
{
	int		i;
	void	*temp;

	i = 0;
	while (i < 2)
	{
		while (1)
		{
			temp = pop_stack(&stackset[i]);
			if (!temp)
				break ;
			free(temp);
		}
		i++;
	}
}

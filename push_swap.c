/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/15 20:52:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"

int	push_swap(int *arr, size_t size)
{
	t_stacks	stacks;

	if (stacks_init(&stacks, arr, size))
		return (1);
	stacks_destroy(&stacks);
	return (0);
}

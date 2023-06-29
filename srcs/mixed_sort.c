/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:53:35 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 21:56:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <ft_printf.h>

void	mixed_sort(t_stackset *stackset, int target_a, int target_b)
{
	int pivot_a;
	int pivot_b;

	//ターゲットが3以下になったら普通にソートしちゃう
	polar_sort(stackset, &target_a, &target_b);
	pivot_a = get_pivot(&stackset->a, target_a);
	pivot_b = get_pivot(&stackset->b, target_b);
	while (1){
		bisection_sort(stackset, &target_a, &target_b);
		if (!target_a && !target_b)
			break;
		//下のほうに分割する
	}
	//	大大と小小の展開　そのmixed_sort
	//	大小と小大の展開　そのmixed_sort
}

// void	bisection_sort(t_stackset *stackset, int target_a, int target_b)
// {
// }

// void	sort_finalize(t_stackset *stackset)
// {
// }

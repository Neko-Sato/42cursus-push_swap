/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:29:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/30 20:23:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

//	ターゲットが片方0になっている場合の最適化
//	まずAに偏っていた場合
//	ピボットより
//	大きいものをBの上小さいものをBの下に分けて
//	分けた後下に分けたものを上部にまたピボットを取得して分割
//	それにmixed_sortを実行、Bのぶんを左に戻して
//	Bの上に振り分けられたものをピボットで逆側に振って
//	mixed_sortをする、
//	Aの上に戻す

void	bisection_sort(t_stackset *stackset, int target[2])
{
	int	flag;
	int	pivot;

	if (target[0] && !target[1])
		flag = 0b10;
	else if (!target[0] && target[1])
		flag = 0b01;
	else
		return ;
	if(flag == 0b10)
	{
		pivot = get_pivot(&stackset->a, target[0]);
		while (1)
		{
			if(stackset->a.tail->value < pivot)

		}
		
	}
}
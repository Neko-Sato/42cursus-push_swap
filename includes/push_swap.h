/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:22:43 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 05:40:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "utils.h"

//	push_swap.c
void	push_swap(int array[], int n);
int		setdata(t_stack stackset[2], int array[], int n);

//	checker.c
void	checker(int array[], int n);

//	sort_stack.c 
int		stack_lt(int value, void *pivot);
int		stack_gt(int value, void *pivot);
int		init_sort(t_stack stackset[2]);
void	finl_sort(t_stack stackset[2]);

//	sort_utils.c
int		get_pivot(t_stack *stack, int target, int reverse);
int		is_sorted(t_stack *stack, int target, int descending);
t_stack	*stack_find(t_stack *stack, int target, t_callable callable);

//	sorts..
void	mixed_sort(t_stack stackset[2], int target[2], int partition);
void	polar_sort(t_stack stackset[2], int target[2]);
void	bisection_sort(t_stack stackset[2], int target[2]);

#endif

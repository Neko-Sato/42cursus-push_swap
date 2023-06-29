/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:22:43 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 22:01:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void	push_swap(int array[], int n);
int		setdata(t_stackset *stackset, int array[], int n);

void	mixed_sort(t_stackset *stackset, int target_a, int target_b);
void	polar_sort(t_stackset *stackset, int *target_a, int *target_b);
void	bisection_sort(t_stackset *stackset, int *target_a, int *target_b);
void	sort_finalize(t_stackset *stackset);

int		get_pivot(t_stack *stack, int target);
int		is_sorted(t_stack *stack, int target, int descending);

void	do_pa(t_stackset *stackset);
void	do_pb(t_stackset *stackset);
void	do_pp(t_stackset *stackset);

void	do_sa(t_stackset *stackset);
void	do_sb(t_stackset *stackset);
void	do_ss(t_stackset *stackset);

void	do_ra(t_stackset *stackset);
void	do_rb(t_stackset *stackset);
void	do_rr(t_stackset *stackset);

void	do_rra(t_stackset *stackset);
void	do_rrb(t_stackset *stackset);
void	do_rrr(t_stackset *stackset);


void	do_p_(t_stackset *stackset, int slect);
void	do_s_(t_stackset *stackset, int slect);
void	do_r_(t_stackset *stackset, int slect);
void	do_rr_(t_stackset *stackset, int slect);

#endif

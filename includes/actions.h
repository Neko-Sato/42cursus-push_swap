/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:21:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 06:42:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "stack.h"

# ifdef DEBUG
#  define STACK_PRINT 1
# else
#  define STACK_PRINT 0
# endif

void	do_pa(t_stack stackset[2], int print);
void	do_pb(t_stack stackset[2], int print);
void	do_pp(t_stack stackset[2], int print);

void	do_sa(t_stack stackset[2], int print);
void	do_sb(t_stack stackset[2], int print);
void	do_ss(t_stack stackset[2], int print);

void	do_ra(t_stack stackset[2], int print);
void	do_rb(t_stack stackset[2], int print);
void	do_rr(t_stack stackset[2], int print);

void	do_rra(t_stack stackset[2], int print);
void	do_rrb(t_stack stackset[2], int print);
void	do_rrr(t_stack stackset[2], int print);

void	do_p_(t_stack stackset[2], int slect, int print);
void	do_s_(t_stack stackset[2], int slect, int print);
void	do_r_(t_stack stackset[2], int slect, int print);
void	do_rr_(t_stack stackset[2], int slect, int print);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:21:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/02 08:07:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "stackset.h"

typedef enum e_actions
{
	_a = 0b01,
	_b = 0b10,
	p_ = 0b001 << 2,
	s_ = 0b010 << 2,
	r_ = 0b011 << 2,
	rr_ = 0b100 << 2,
	pa = p_ | _a,
	pb = p_ | _b,
	sa = s_ | _a,
	sb = s_ | _b,
	ss = s_ | _a | _b,
	ra = r_ | _a,
	rb = r_ | _b,
	rr = r_ | _a | _b,
	rra = rr_ | _a,
	rrb = rr_ | _b,
	rrr = rr_ | _a | _b,
}				t_actions;

typedef void	(*t_do_action)(t_stackset *s, int print);

void			do_action(t_stackset *s, t_actions action, int print);
void			do_actions(t_stackset *s, t_actions *actions, size_t len, int print);

void			do_pa(t_stackset *s, int print);
void			do_pb(t_stackset *s, int print);

void			do_sa(t_stackset *s, int print);
void			do_sb(t_stackset *s, int print);
void			do_ss(t_stackset *s, int print);

void			do_ra(t_stackset *s, int print);
void			do_rb(t_stackset *s, int print);
void			do_rr(t_stackset *s, int print);

void			do_rra(t_stackset *s, int print);
void			do_rrb(t_stackset *s, int print);
void			do_rrr(t_stackset *s, int print);

#endif
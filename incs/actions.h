/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:21:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 19:52:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "stackset.h"

typedef enum e_actions
{
	error = -1,
	noaction = 0,
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

t_actions		str2action(char *str);
char			*astion2str(t_actions action);
void			do_action(t_stackset *s, t_actions action, int set_buff);
void			do_actions(t_stackset *s, t_actions *actions, size_t len,
					int set_buff);

//	do_action
typedef void	(*t_do_action)(t_stackset *s);

void			do_pa(t_stackset *s);
void			do_pb(t_stackset *s);

void			do_sa(t_stackset *s);
void			do_sb(t_stackset *s);
void			do_ss(t_stackset *s);

void			do_ra(t_stackset *s);
void			do_rb(t_stackset *s);
void			do_rr(t_stackset *s);

void			do_rra(t_stackset *s);
void			do_rrb(t_stackset *s);
void			do_rrr(t_stackset *s);

//	optimized
int				optimized_action(t_actions actions[4]);

void			set_action_buff(t_actions action);
void			put_action_buff(void);
void			optimized_action_buff(void);

#endif
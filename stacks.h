/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:23:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 03:42:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stddef.h>

typedef enum e_stackname
{
	STACK_A,
	STACK_B,
	_STACK_SIZE
}			t_stackname;

typedef struct s_stacks
{
	int		*data;
	size_t	size;
	size_t	head[_STACK_SIZE];
	size_t	len[_STACK_SIZE];
}			t_stacks;

int			stacks_init(t_stacks *stacks, int *data, size_t size);
void		stacks_destroy(t_stacks *stacks);
size_t		_stacks_buffer_index(const t_stacks *stacks,
				t_stackname name, long p);
size_t		stacks_index(const t_stacks *stacks, t_stackname name, long p);
void		stacks_print(const t_stacks *stacks);
int			stacks_check(const t_stacks *stacks);

void		stacks_pa(t_stacks *s);
void		stacks_pb(t_stacks *s);
void		stacks_sa(t_stacks *s);
void		stacks_sb(t_stacks *s);
void		stacks_ss(t_stacks *s);
void		stacks_ra(t_stacks *s);
void		stacks_rb(t_stacks *s);
void		stacks_rr(t_stacks *s);
void		stacks_rra(t_stacks *s);
void		stacks_rrb(t_stacks *s);
void		stacks_rrr(t_stacks *s);

#endif

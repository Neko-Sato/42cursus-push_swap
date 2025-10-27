/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:23:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/27 16:21:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <libft.h>
# include <stddef.h>

typedef enum e_stackname
{
	STACK_A,
	STACK_B,
	_STACK_SIZE
}			t_stackname;

typedef struct s_stacks
{
	int		*_data;
	size_t	_size;
	size_t	_head[_STACK_SIZE];
	size_t	_len[_STACK_SIZE];
}			t_stacks;

typedef enum e_action
{
	MASK_NAME = 0x3,
	MASK_ACT = 0xc,
	ACT_NONE = 0,
	_ACT__A = 0x1,
	_ACT__B = 0x2,
	_ACT_S_ = 0,
	_ACT_P_ = 0x4,
	_ACT_R_ = 0x8,
	_ACT_RR_ = 0xc,
	ACT_SA = _ACT_S_ | _ACT__A,
	ACT_SB = _ACT_S_ | _ACT__B,
	ACT_SS = _ACT_S_ | _ACT__A | _ACT__B,
	ACT_PA = _ACT_P_ | _ACT__A,
	ACT_PB = _ACT_P_ | _ACT__B,
	ACT_RA = _ACT_R_ | _ACT__A,
	ACT_RB = _ACT_R_ | _ACT__B,
	ACT_RR = _ACT_R_ | _ACT__A | _ACT__B,
	ACT_RRA = _ACT_RR_ | _ACT__A,
	ACT_RRB = _ACT_RR_ | _ACT__B,
	ACT_RRR = _ACT_RR_ | _ACT__A | _ACT__B,
	_ACT_SIZE,
}							t_action;

int			stacks_init(t_stacks *stacks, int *data, size_t size);
void		stacks_destroy(t_stacks *stacks);
size_t		_stacks_buffer_index(const t_stacks *stacks, t_stackname name,
				long p);
size_t		_stacks_index(const t_stacks *stacks, t_stackname name, long p);
size_t		stacks_len(const t_stacks *stacks, t_stackname name);
int			stacks_at(const t_stacks *stacks, t_stackname name, long p);

void		stacks_print(const t_stacks *stacks, int fd);
int			stacks_check(const t_stacks *stacks);
int			stacks_cmd(t_stacks *stacks, const char *cmd);
int			stacks_istream(t_stacks *stacks, t_istream *is);
void		stacks_binary(t_stacks *s, void *data, size_t n);

#endif

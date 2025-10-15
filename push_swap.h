/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:23:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 03:04:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stacks.h"
# include <stddef.h>

typedef struct s_action_entry
{
	const char	*cmd;
	void		(*fun)(t_stacks *stacks);
}				t_action_entry;

int				push_swap(int *arr, size_t size);
int				checker(int *arr, size_t size);
int				atoi_array(int *arr, char **srcs, size_t size);
int				compress_coords(int *arr, size_t size);

#endif

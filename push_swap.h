/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:23:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 03:21:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stacks.h"
# include "optimization.h"
# include <stddef.h>

int				push_swap(int *arr, size_t size);
int				checker(int *arr, size_t size);
int				atoi_array(int *arr, char **srcs, size_t size);
int				normalization(int *arr, size_t size);

int				small_sort(t_stacks *stacks, t_action_buffer *buf);
int				middle_sort(t_stacks *stacks, t_action_buffer *buf);
int				large_sort(t_stacks *stacks, t_action_buffer *buf);

#endif

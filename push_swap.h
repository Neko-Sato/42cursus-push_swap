/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:23:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 17:01:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stacks.h"
# include <stddef.h>

int				push_swap(int *arr, size_t size);
int				checker(int *arr, size_t size);
int				atoi_array(int *arr, char **srcs, size_t size);
int				compress_coords(int *arr, size_t size);

int				small_sort(t_stacks *stacks);
int				middle_sort(t_stacks *stacks);
int				large_sort(t_stacks *stacks);

#endif

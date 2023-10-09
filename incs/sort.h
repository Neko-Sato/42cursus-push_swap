/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:17:59 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 02:38:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stackset.h"

void	small_sort(t_stackset *s, size_t len, void *buff);
void	insert_sort_stacka(t_stackset *s, size_t len, void *buff);
void	insert_sort_stackb_top(t_stackset *s, size_t len, void *buff);
void	insert_sort_stackb_bottom(t_stackset *s, size_t len, void *buff);
void	quick_sort_stacka(t_stackset *s, size_t len, void *buff);
void	quick_sort_stackb_top(t_stackset *s, size_t len, void *buff);
void	quick_sort_stackb_bottom(t_stackset *s, size_t len, void *buff);

int		get_pivot(t_stackset *s, int stack, int len);
int		is_sorted(t_stackset *s, int stack, size_t len);
int		get_next_put_lt(t_stackset *s, int stack, int len, int pivot);

#endif
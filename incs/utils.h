/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:45:51 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 20:18:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stackset.h>
# include <stddef.h>

int		compress_array(int arry[], size_t len);
int		get_pivot(t_stackset *s, int stack, int len);
int		is_sorted(t_stackset *s, size_t len);
int		get_next_put_lt(t_stackset *s, int stack, int len, int pivot);

#endif

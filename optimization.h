/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:02:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 01:42:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZATION_H
# define OPTIMIZATION_H

# include "stacks.h"

typedef struct s_action_buffer
{
	t_action		buf[8];
	unsigned int	size;
}					t_action_buffer;

typedef struct s_optimize_entry
{
	int				code;
	t_action		action;
}					t_optimize_entry;

void				action_buffer_put(t_action_buffer *buffer, t_action action);
void				action_buffer_flush(t_action_buffer *buffer);

#endif

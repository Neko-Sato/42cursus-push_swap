/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:02:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/22 17:45:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZATION_H
# define OPTIMIZATION_H

# include "stacks.h"

typedef struct s_optimizer
{
	unsigned int	buf;
	unsigned int	size;
}					t_optimizer;

typedef struct s_optimize_entry
{
	unsigned int	code;
	t_action		action;
}					t_optimize_entry;

void				optimizer_put(t_optimizer *buffer, t_action action);
void				optimizer_flush(t_optimizer *buffer);

#endif

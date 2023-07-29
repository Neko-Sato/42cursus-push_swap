/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:52:10 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 01:54:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef int(*t_callable_fun)();

typedef struct s_callable
{
	t_callable_fun	fun;
	void			*args;
}	t_callable;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif
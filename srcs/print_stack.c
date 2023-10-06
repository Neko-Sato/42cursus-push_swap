/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:27:18 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 03:27:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include <libft.h>

void	print_stack(t_stackset *s)
{
	size_t	i;

	ft_putstr_fd("a: ", 1);
	i = 0;
	while (i < s->vars.len[0])
	{
		ft_putnbr_fd(s->stack[get_index(&s->vars, 0, i++)], 1);
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\nb: ", 1);
	i = 0;
	while (i < s->vars.len[1])
	{
		ft_putnbr_fd(s->stack[get_index(&s->vars, 1, i++)], 1);
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\n\n", 1);
}

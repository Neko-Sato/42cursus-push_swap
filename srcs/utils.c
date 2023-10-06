/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:31:54 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/06 20:27:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackset.h"
#include <libft.h>

int	is_sorted(t_stackset *s, size_t len)
{
	int		ret;
	size_t	i;
	int		temp[2];

	if (len < 2)
		return (1);
	ret = 1;
	i = 0;
	temp[0] = stackat(s, 0, i++);
	while (ret && i < len)
	{
		temp[1] = stackat(s, 0, i++);
		if (temp[0] > temp[1])
			ret &= 0;
		temp[0] = temp[1];
	}
	return (ret);
}

int	get_pivot(t_stackset *s, int stack, int len)
{
	int		i;
	double	ret;
	int		sign;
	int		start;

	sign = ft_sign(len);
	start = -(sign < 0);
	len = ft_abs(len);
	i = 0;
	ret = 0.;
	while (i < len)
		ret += stackat(s, stack, start + sign * i++) / (double)len;
	return ((int)ret);
}

int	get_next_put_lt(t_stackset *s, int stack, int len, int pivot)
{
	int		i;
	int		temp;
	int		sign;
	int		start;

	sign = ft_sign(len);
	start = -(sign < 0);
	len = ft_abs(len);
	i = 0;
	while (i < len)
	{
		temp = stackat(s, stack, start + sign * i++);
		if (temp < pivot)
			return (temp);
	}
	return (-1);
}

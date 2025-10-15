/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:34:45 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/15 20:35:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <limits.h>

int	atoi_array(int *arr, char **srcs, size_t size)
{
	size_t	i;
	char	*endptr;
	long	tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_strtol(srcs[i], &endptr, 10);
		if (endptr == srcs[i] || *endptr
			|| tmp < (long)INT_MIN || (long)INT_MAX < tmp)
			return (1);
		arr[i] = tmp;
		i++;
	}
	return (0);
}

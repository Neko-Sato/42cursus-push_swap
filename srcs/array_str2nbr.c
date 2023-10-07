/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_str2nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:24:15 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 20:30:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <limits.h>
#include <stdlib.h>

int	*array_str2nbr(char *str_array[], size_t len)
{
	int		*array;
	long	temp;
	size_t	i;

	array = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (!ft_isnumber(str_array[i]))
		{
			free(array);
			return (NULL);
		}
		temp = ft_atol(str_array[i]);
		if (errno || !(INT_MIN <= temp && temp <= INT_MAX))
		{
			free(array);
			return (NULL);
		}
		array[i] = (int)temp;
		i++;
	}
	return (array);
}

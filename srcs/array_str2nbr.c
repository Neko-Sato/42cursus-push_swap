/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:24:15 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 02:55:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	*array_str2nbr(char *str_array[], size_t len)
{
	int		*array;
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
		array[i] = ft_atoi(str_array[i]);
		i++;
	}
	return (array);
}

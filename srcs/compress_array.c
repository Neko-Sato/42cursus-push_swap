/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:12:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/01 04:03:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

static size_t	get_index(int arry[], size_t len, int n);

void	compress_array(int arry[], size_t len)
{
	size_t	i;
	int		sorted[len];

	ft_memcpy(sorted, arry, sizeof(int) * len);
	ft_sort(sorted, len);
	i = 0;
	while (i < len)
	{
		arry[i] = get_index(sorted, len, arry[i]);
		i++;
	}
}

static size_t	get_index(int arry[], size_t len, int n)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (arry[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

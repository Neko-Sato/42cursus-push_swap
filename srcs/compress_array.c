/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:12:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 04:04:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static size_t	get_index(int arry[], size_t len, int n);
static int		has_consecutive_duplicates(int arry[], size_t len);

int	compress_array(int arry[], size_t len)
{
	size_t	i;
	int		*sorted;

	sorted = (int *)malloc(sizeof(int) * len);
	if (!sorted)
		return (-1);
	ft_memcpy(sorted, arry, sizeof(int) * len);
	ft_sort(sorted, len);
	if (has_consecutive_duplicates(sorted, len))
	{
		free(sorted);
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		arry[i] = get_index(sorted, len, arry[i]);
		i++;
	}
	free(sorted);
	return (0);
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

static int	has_consecutive_duplicates(int arry[], size_t len)
{
	size_t	i;

	i = 1;
	while (i < len)
	{
		if (arry[i - 1] == arry[i])
			return (1);
		i++;
	}
	return (0);
}

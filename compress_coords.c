/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:40:16 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 02:43:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int	compress_coords(int *arr, size_t size)
{
	int		*copy;
	size_t	i;
	size_t	j;

	copy = ft_memdup(arr, sizeof(int) * size);
	if (!copy)
		return (1);
	ft_qsort(&(t_qsort){copy, size, sizeof(int), (int (*)(const void *,
				const void *))ft_intcmp});
	i = 0;
	j = 0;
	while (i < size)
		if (copy[j] != copy[i++])
			copy[++j] = copy[i - 1];
	i = (j++, 0);
	while (i < size)
	{
		arr[i] = (int *)ft_bsearch(&(t_bsearch){&arr[i], copy, j, sizeof(int),
				(int (*)(const void *, const void *))ft_intcmp}) - copy;
		i++;
	}
	return (free(copy), 0);
}

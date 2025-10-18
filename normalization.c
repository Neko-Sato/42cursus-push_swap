/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:40:16 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/19 03:45:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static inline int	_internal(int *copy, int *arr, size_t size)
{
	size_t	i;

	ft_qsort(&(t_qsort){copy, size, sizeof(int), (int (*)(const void *,
				const void *))ft_intcmp});
	i = 1;
	while (i < size)
	{
		if (copy[i - 1] == copy[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = (int *)ft_bsearch(&(t_bsearch){&arr[i], copy, size,
				sizeof(int), (int (*)(const void *, const void *))ft_intcmp})
			- copy;
		i++;
	}
	return (0);
}

int	normalization(int *arr, size_t size)
{
	int	tmp;
	int	*copy;

	copy = ft_memdup(arr, sizeof(int) * size);
	if (!copy)
		return (1);
	tmp = _internal(copy, arr, size);
	free(copy);
	return (tmp);
}

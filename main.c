/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:33:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/15 20:48:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		tmp;
	size_t	size;
	int		*arr;

	size = argc - 1;
	arr = malloc(sizeof(int) * size);
	tmp = !arr
		|| atoi_array(arr, &argv[1], size)
		|| compress_coords(arr, size)
		|| push_swap(arr, size);
	if (tmp)
		ft_dprintf(STDERR_FILENO, "Error\n");
	free(arr);
	return (tmp);
}

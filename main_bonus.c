/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:46:55 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 03:35:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>
#include <stdlib.h>
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
		|| checker(arr, size);
	if (tmp)
		ft_dprintf(STDERR_FILENO, "Error\n");
	free(arr);
	return (tmp);
}

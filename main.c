/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:33:54 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/29 16:51:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <ft_printf.h>
#include <stdlib.h>

int	pars_args(int *dst, char *src[], int n)
{
	while (n--)
	{
		if (!ft_isdigit(*src[n]))
			return (1);
		dst[n] = ft_atoi(src[n]);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*args;

	args = (int *)malloc((argc - 1) * sizeof(int));
	if (args && !pars_args(args, &argv[1], argc - 1))
		push_swap(args, argc - 1);
	else
		ft_printf("Error\n");
	free(args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:33:54 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 04:21:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static int	checker_main(char *src[], size_t n);

int	main(int argc, char *argv[])
{
	if (checker_main(&argv[1], argc - 1))
		ft_putendl_fd("Error", STDERR_FILENO);
}

static int	checker_main(char *src[], size_t n)
{
	int ret;
	int *args;

	args = array_str2nbr(src, n);
	if (!args)
		return (-1);
	ret = checker(args, n);
	free(args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/27 16:16:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include <libft.h>
#include <ft_printf.h>
#include <unistd.h>

int	push_swap(int *arr, size_t size)
{
	int			tmp;
	t_stacks	stacks;

	if (stacks_init(&stacks, arr, size))
		return (1);
	tmp = 0;
	if (!stacks_check(&stacks))
	{
		(void)0;
	}
	stacks_destroy(&stacks);
	return (tmp);
}

int	checker(int *arr, size_t size)
{
	int			tmp;
	t_stacks	stacks;
	char		buf[1024];
	int			fd;
	t_istream	is;

	if (stacks_init(&stacks, arr, size))
		return (1);
	fd = STDIN_FILENO;
	ft_istream_init(&is, &(t_istream_init){buf, sizeof(buf), ft__read_fd, &fd});
	tmp = stacks_istream(&stacks, &is);
	if (!tmp)
		ft_printf("%s\n", (const char *[]){"KO", "OK"}[stacks_check(&stacks)]);
	ft_istream_destroy(&is);
	stacks_destroy(&stacks);
	return (tmp);
}

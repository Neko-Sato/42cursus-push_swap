/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:35:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/21 21:37:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stacks.h"
#include "optimization.h"
#include <libft.h>
#include <ft_printf.h>
#include <unistd.h>

void	do_action(t_stacks *stacks, t_optimizer *buf, t_action action)
{
	g_actions[action].fun(stacks);
	optimizer_put(buf, action);
}

int	push_swap(int *arr, size_t size)
{
	int			tmp;
	t_stacks	stacks;
	t_optimizer	buffer;

	if (stacks_init(&stacks, arr, size))
		return (1);
	ft_memset(&buffer, 0, sizeof(t_optimizer));
	tmp = 0;
	if (!stacks_check(&stacks))
	{
		if (size <= 6)
			tmp = small_sort(&stacks, &buffer);
		else if (size <= 100)
			tmp = middle_sort(&stacks, &buffer);
		else
			tmp = large_sort(&stacks, &buffer);
	}
	optimizer_flush(&buffer);
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
	if (ft_istream_init(&is, &(t_istream_init){
			buf, sizeof(buf), ft__read_fd, &fd}))
	{
		stacks_destroy(&stacks);
		return (1);
	}
	tmp = stacks_istream(&stacks, &is);
	if (!tmp)
		ft_printf("%s\n", (const char *[]){"KO", "OK"}[stacks_check(&stacks)]);
	ft_istream_destroy(&is);
	stacks_destroy(&stacks);
	return (tmp);
}

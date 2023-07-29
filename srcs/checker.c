/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:46:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/30 06:40:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "actions.h"
#include "utils.h"
#include "get_next_line.h"
#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

static int	move(t_stack stackset[2]);
static int	do_cmd(t_stack stackset[2], const char *cmd);

void	checker(int array[], int n)
{
	t_stack	stackset[2];

	if (!setdata(stackset, array, n))
	{
		move(stackset);
		if (is_sorted(stackset, n, 1))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		write(2, "Error\n", 6);
	finl_stackset(stackset);
}

static int	move(t_stack stackset[2])
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (do_cmd(stackset, cmd))
			return (1);
	}
	return (0);
}

static int	do_cmd(t_stack stackset[2], const char *cmd)
{
	if (!ft_strncmp(cmd, "pa", 2))
		do_pa(stackset, 0);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		do_pb(stackset, 0);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		do_sa(stackset, 0);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		do_sb(stackset, 0);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		do_ss(stackset, 0);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		do_ra(stackset, 0);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		do_rb(stackset, 0);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		do_rr(stackset, 0);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		do_rra(stackset, 0);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		do_rrb(stackset, 0);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		do_rrr(stackset, 0);
	else
		return (1);
	return (0);
}

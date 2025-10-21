/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:02:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/21 21:26:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimization.h"
#include "stacks.h"
#include <ft_printf.h>
#include <libft.h>

static const t_optimize_entry	g_optimize_entries[] = {
{ACT_SA << 4 | ACT_SA, ACT_NONE},
{ACT_SA << 4 | ACT_SB, ACT_SS},
{ACT_SA << 4 | ACT_SS, ACT_SB},
{ACT_SB << 4 | ACT_SA, ACT_SS},
{ACT_SB << 4 | ACT_SB, ACT_NONE},
{ACT_SB << 4 | ACT_SS, ACT_SA},
{ACT_SS << 4 | ACT_SA, ACT_SB},
{ACT_SS << 4 | ACT_SB, ACT_SA},
{ACT_SS << 4 | ACT_SS, ACT_NONE},
{ACT_PA << 4 | ACT_PB, ACT_NONE},
{ACT_PB << 4 | ACT_PA, ACT_NONE},
{ACT_RA << 4 | ACT_RB, ACT_RR},
{ACT_RA << 4 | ACT_RRA, ACT_NONE},
{ACT_RA << 4 | ACT_RRR, ACT_RRB},
{ACT_RB << 4 | ACT_RA, ACT_RR},
{ACT_RB << 4 | ACT_RRB, ACT_NONE},
{ACT_RB << 4 | ACT_RRR, ACT_RRA},
{ACT_RR << 4 | ACT_RRA, ACT_RB},
{ACT_RR << 4 | ACT_RRB, ACT_RA},
{ACT_RR << 4 | ACT_RRR, ACT_NONE},
{ACT_RRA << 4 | ACT_RA, ACT_NONE},
{ACT_RRA << 4 | ACT_RR, ACT_RB},
{ACT_RRA << 4 | ACT_RRB, ACT_RRR},
{ACT_RRB << 4 | ACT_RB, ACT_NONE},
{ACT_RRB << 4 | ACT_RR, ACT_RA},
{ACT_RRB << 4 | ACT_RRA, ACT_RRR},
{ACT_RRR << 4 | ACT_RA, ACT_RRB},
{ACT_RRR << 4 | ACT_RB, ACT_RRA},
{ACT_RRR << 4 | ACT_RR, ACT_NONE},
{((ACT_SA << 4 | ACT_PB) << 4 | ACT_RA) << 4 | ACT_PA, ACT_RA},
{((ACT_SA << 4 | ACT_RA) << 4 | ACT_SB) << 4 | ACT_RRA, ACT_SS},
{((ACT_SA << 4 | ACT_RA) << 4 | ACT_PB) << 4 | ACT_RRA, ACT_PB},
{((ACT_SA << 4 | ACT_RB) << 4 | ACT_SA) << 4 | ACT_RA, ACT_RR},
{((ACT_SA << 4 | ACT_RB) << 4 | ACT_SA) << 4 | ACT_RRB, ACT_NONE},
{((ACT_SA << 4 | ACT_RB) << 4 | ACT_SA) << 4 | ACT_RRR, ACT_RRA},
{((ACT_SA << 4 | ACT_RRA) << 4 | ACT_SB) << 4 | ACT_RA, ACT_SS},
{((ACT_SA << 4 | ACT_RRB) << 4 | ACT_SA) << 4 | ACT_RB, ACT_NONE},
{((ACT_SA << 4 | ACT_RRB) << 4 | ACT_SA) << 4 | ACT_RR, ACT_RA},
{((ACT_SA << 4 | ACT_RRB) << 4 | ACT_SA) << 4 | ACT_RRA, ACT_RRR},
{((ACT_SB << 4 | ACT_PA) << 4 | ACT_RB) << 4 | ACT_PB, ACT_RB},
{((ACT_SB << 4 | ACT_RA) << 4 | ACT_SB) << 4 | ACT_RB, ACT_RR},
{((ACT_SB << 4 | ACT_RA) << 4 | ACT_SB) << 4 | ACT_RRA, ACT_NONE},
{((ACT_SB << 4 | ACT_RA) << 4 | ACT_SB) << 4 | ACT_RRR, ACT_RRB},
{((ACT_SB << 4 | ACT_RB) << 4 | ACT_SA) << 4 | ACT_RRB, ACT_SS},
{((ACT_SB << 4 | ACT_RB) << 4 | ACT_PA) << 4 | ACT_RRB, ACT_PA},
{((ACT_SB << 4 | ACT_RRA) << 4 | ACT_SB) << 4 | ACT_RA, ACT_NONE},
{((ACT_SB << 4 | ACT_RRA) << 4 | ACT_SB) << 4 | ACT_RR, ACT_RB},
{((ACT_SB << 4 | ACT_RRA) << 4 | ACT_SB) << 4 | ACT_RRB, ACT_RRR},
{((ACT_SB << 4 | ACT_RRB) << 4 | ACT_SA) << 4 | ACT_RB, ACT_SS},
{((ACT_SS << 4 | ACT_RA) << 4 | ACT_SB) << 4 | ACT_RRA, ACT_SA},
{((ACT_SS << 4 | ACT_RB) << 4 | ACT_SA) << 4 | ACT_RRB, ACT_SB},
{((ACT_SS << 4 | ACT_RRA) << 4 | ACT_SB) << 4 | ACT_RA, ACT_SA},
{((ACT_SS << 4 | ACT_RRB) << 4 | ACT_SA) << 4 | ACT_RB, ACT_SB},
{((ACT_PA << 4 | ACT_SA) << 4 | ACT_RA) << 4 | ACT_PB, ACT_RA},
{((ACT_PA << 4 | ACT_RB) << 4 | ACT_PB) << 4 | ACT_RRB, ACT_SB},
{((ACT_PA << 4 | ACT_RRA) << 4 | ACT_SA) << 4 | ACT_PB, ACT_RRA},
{((ACT_PA << 4 | ACT_RRB) << 4 | ACT_PB) << 4 | ACT_SB, ACT_RRB},
{((ACT_PB << 4 | ACT_SB) << 4 | ACT_RB) << 4 | ACT_PA, ACT_RB},
{((ACT_PB << 4 | ACT_RA) << 4 | ACT_PA) << 4 | ACT_RRA, ACT_SA},
{((ACT_PB << 4 | ACT_RRA) << 4 | ACT_PA) << 4 | ACT_SA, ACT_RRA},
{((ACT_PB << 4 | ACT_RRB) << 4 | ACT_SB) << 4 | ACT_PA, ACT_RRB},
{((ACT_RA << 4 | ACT_SA) << 4 | ACT_RB) << 4 | ACT_SA, ACT_RR},
{((ACT_RA << 4 | ACT_SB) << 4 | ACT_RRA) << 4 | ACT_SA, ACT_SS},
{((ACT_RA << 4 | ACT_SB) << 4 | ACT_RRA) << 4 | ACT_SB, ACT_NONE},
{((ACT_RA << 4 | ACT_SB) << 4 | ACT_RRA) << 4 | ACT_SS, ACT_SA},
{((ACT_RA << 4 | ACT_PA) << 4 | ACT_RRA) << 4 | ACT_SA, ACT_PA},
{((ACT_RA << 4 | ACT_PB) << 4 | ACT_RRA) << 4 | ACT_PA, ACT_SA},
{((ACT_RB << 4 | ACT_SA) << 4 | ACT_RRB) << 4 | ACT_SA, ACT_NONE},
{((ACT_RB << 4 | ACT_SA) << 4 | ACT_RRB) << 4 | ACT_SB, ACT_SS},
{((ACT_RB << 4 | ACT_SA) << 4 | ACT_RRB) << 4 | ACT_SS, ACT_SB},
{((ACT_RB << 4 | ACT_SB) << 4 | ACT_RA) << 4 | ACT_SB, ACT_RR},
{((ACT_RB << 4 | ACT_PA) << 4 | ACT_RRB) << 4 | ACT_PB, ACT_SB},
{((ACT_RB << 4 | ACT_PB) << 4 | ACT_RRB) << 4 | ACT_SB, ACT_PB},
{((ACT_RR << 4 | ACT_SA) << 4 | ACT_RRB) << 4 | ACT_SA, ACT_RA},
{((ACT_RR << 4 | ACT_SB) << 4 | ACT_RRA) << 4 | ACT_SB, ACT_RB},
{((ACT_RRA << 4 | ACT_SA) << 4 | ACT_PB) << 4 | ACT_RA, ACT_PB},
{((ACT_RRA << 4 | ACT_SA) << 4 | ACT_RRB) << 4 | ACT_SA, ACT_RRR},
{((ACT_RRA << 4 | ACT_SB) << 4 | ACT_RA) << 4 | ACT_SA, ACT_SS},
{((ACT_RRA << 4 | ACT_SB) << 4 | ACT_RA) << 4 | ACT_SB, ACT_NONE},
{((ACT_RRA << 4 | ACT_SB) << 4 | ACT_RA) << 4 | ACT_SS, ACT_SA},
{((ACT_RRA << 4 | ACT_PA) << 4 | ACT_SA) << 4 | ACT_RA, ACT_PA},
{((ACT_RRB << 4 | ACT_SA) << 4 | ACT_RB) << 4 | ACT_SA, ACT_NONE},
{((ACT_RRB << 4 | ACT_SA) << 4 | ACT_RB) << 4 | ACT_SB, ACT_SS},
{((ACT_RRB << 4 | ACT_SA) << 4 | ACT_RB) << 4 | ACT_SS, ACT_SB},
{((ACT_RRB << 4 | ACT_SB) << 4 | ACT_PA) << 4 | ACT_RB, ACT_PA},
{((ACT_RRB << 4 | ACT_SB) << 4 | ACT_RRA) << 4 | ACT_SB, ACT_RRR},
{((ACT_RRB << 4 | ACT_PB) << 4 | ACT_SB) << 4 | ACT_RB, ACT_PB},
{((ACT_RRR << 4 | ACT_SA) << 4 | ACT_RB) << 4 | ACT_SA, ACT_RRA},
{((ACT_RRR << 4 | ACT_SB) << 4 | ACT_RA) << 4 | ACT_SB, ACT_RRB},
};

static const size_t				g_optimize_entries_size
	= sizeof(g_optimize_entries) / sizeof(g_optimize_entries[0]);

static int	_comper(const void *a, const void *b)
{
	const unsigned int	ac = ((t_optimize_entry *)a)->code;
	const unsigned int	bc = ((t_optimize_entry *)b)->code;

	return ((ac > bc) - (ac < bc));
}

static void	_optimize(t_optimizer *buffer)
{
	unsigned int		n;
	unsigned int		tmp;
	t_optimize_entry	*find;

	tmp = 0;
	n = 0;
	while (n < 4 && n < buffer->size)
	{
		tmp = tmp << 4 | buffer->buf[n++];
		if (n != 2 && n != 4)
			continue ;
		find = ft_bsearch(&(t_bsearch){&tmp, g_optimize_entries,
				g_optimize_entries_size, sizeof(t_optimize_entry), _comper});
		if (find)
		{
			tmp = find->action != ACT_NONE;
			buffer->buf[0] = find->action;
			ft_memcpy(&buffer->buf[tmp], &buffer->buf[n],
				sizeof(t_action) * (buffer->size - n));
			buffer->size -= n - tmp;
			tmp = 0;
			n = 0;
			continue ;
		}
	}
}

void	optimizer_put(t_optimizer *buffer, t_action action)
{
	if (action == ACT_NONE)
		return ;
	buffer->buf[buffer->size++] = action;
	if (buffer->size < 8)
		return ;
	_optimize(buffer);
	if (buffer->size < 8)
		return ;
	ft_printf("%s\n", g_actions[buffer->buf[0]].cmd);
	ft_memcpy(&buffer->buf[0], &buffer->buf[1], sizeof(t_action[7]));
	buffer->size--;
}

void	optimizer_flush(t_optimizer *buffer)
{
	while (1)
	{
		_optimize(buffer);
		if (!buffer->size)
			break ;
		ft_printf("%s\n", g_actions[buffer->buf[0]].cmd);
		ft_memcpy(&buffer->buf[0], &buffer->buf[1],
			sizeof(t_action) * --buffer->size);
	}
}

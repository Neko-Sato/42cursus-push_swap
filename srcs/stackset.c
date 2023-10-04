#include "stackset.h"
#include <libft.h>
#include <stdlib.h>

t_stackset	*new_stackset(int array[], size_t len)
{
	t_stackset	*s;

	s = (t_stackset *)malloc(sizeof(t_stackset));
	if (!s)
		return (NULL);
	s->stack = (int *)malloc(sizeof(int) * len * 2);
	if (!s->stack)
	{
		free(s);
		return (NULL);
	}
	ft_memcpy(s->stack, array, sizeof(int) * len);
	s->vars.size = len;
	s->vars.head[0] = 0;
	s->vars.len[0] = len;
	s->vars.head[1] = 0;
	s->vars.len[1] = 0;
	return (s);
}

void	del_stackset(t_stackset *s)
{
	if (s)
	{
		free(s->stack);
		free(s);
	}
}

int	stackat(t_stackset *s, int stack, int i)
{
	return (s->stack[get_index(&s->vars, stack, i)]);
}

size_t	get_index_stack(t_stackset_vars *vars, int stack, int i)
{
	while (i < 0)
		i += vars->size;
	return (vars->size * stack + (vars->head[stack] + i) % vars->size);
}

size_t	get_index(t_stackset_vars *vars, int stack, int i)
{
	while (i < 0)
		i += vars->len[stack];
	return (get_index_stack(vars, stack, i % vars->len[stack]));
}

void	print_stack(t_stackset *s)
{
	size_t	i;

	ft_putstr_fd("a: ", 1);
	i = 0;
	while (i < s->vars.len[0])
	{
		ft_putnbr_fd(s->stack[get_index(&s->vars, 0, i++)], 1);
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\nb: ", 1);
	i = 0;
	while (i < s->vars.len[1])
	{
		ft_putnbr_fd(s->stack[get_index(&s->vars, 1, i++)], 1);
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\n\n", 1);
}

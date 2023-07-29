#include "includes/push_swap.h"

int	testsetdata(t_stack stackset[2], int array[], int n[2])
{
	void	*element;
	int		i, j;

	init_stackset(stackset);
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (n[i]--)
		{
			element = new_stack_element(&array[j++]);
			if (!element)
				return (1);
			push_stack(&stackset[i], element);
		}
	i++;
	}
	return (0);
}

int main()
{
	int p;
	t_stack stackset[2];

	testsetdata(stackset, (int []){14, 74, 90, 72, 75, 91, 76, 45, 80, 26, 50, 66, 6, 39, 7, 56, 84, 99, 33, 4, 35, 0, 8, 86, 95, 20, 60, 65, 96, 77, 24, 23, 43, 59, 40, 81, 71, 9, 83, 28, 48, 88, 16, 58, 3, 54, 55, 15, 18, 57}, (int []){50, 0});
	p = init_sort(stackset);
	mixed_sort(stackset, (int [2]){stack_len(&stackset[0]), stack_len(&stackset[1])}, p);
	finl_sort(stackset);
	print_stackset(stackset);
	finl_stackset(stackset);
}
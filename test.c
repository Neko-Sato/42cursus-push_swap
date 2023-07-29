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

	testsetdata(stackset, (int []){126, 101, 36, 174, 88, 135, 9, 162, 129, 98, 62, 95, 158, 55, 79, 139, 133, 171, 184, 4, 74, 96, 151, 37, 91, 39, 93, 31, 114, 84, 161, 1, 185, 51, 142, 67, 64, 140, 61, 112, 124, 49, 12, 111, 188, 104, 143, 14, 40, 118, 183, 71, 72, 173, 165, 24, 26, 169, 193, 120, 42, 47, 86, 106, 15, 116, 83, 144, 187, 63, 192, 57, 145, 21, 56, 177, 18, 119, 109, 148, 34, 153, 159, 7, 186, 87, 11, 23, 58, 157, 22, 30, 196, 146, 180, 168, 43, 113, 122, 195}, (int []){100, 0});
	p = init_sort(stackset);
	mixed_sort(stackset, (int [2]){stack_len(&stackset[0]), stack_len(&stackset[1])}, p);
	finl_sort(stackset);
	// print_stackset(stackset);
	finl_stackset(stackset);
}
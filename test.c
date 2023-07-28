#include "includes/push_swap.h"

int	testsetdata(t_stackset *stackset, int array[], int n[2])
{
	void	*element;
	int		i;

	init_stackset(stackset);
	i = 0;
	while (n[0]--)
	{
		element = new_stack_element(&array[i++]);
		if (!element)
			return (1);
		push_stack(&stackset->a, element);
	}
	while (n[1]--)
	{
		element = new_stack_element(&array[i++]);
		if (!element)
			return (1);
		push_stack(&stackset->b, element);
	}
	return (0);
}

int main()
{
	t_stackset stackset;

	testsetdata(&stackset, (int []){14, 74, 90, 72, 75, 91, 76, 45, 80, 26, 50, 66, 6, 39, 7, 56, 84, 99, 33, 4, 35, 0, 8, 86, 95, 20, 60, 65, 96, 77, 24, 23, 43, 59, 40, 81, 71, 9, 83, 28, 48, 88, 16, 58, 3, 54, 55, 15, 18, 57}, (int []){50, 0});
	mixed_sort(&stackset, (int [2]){50, 0});
	finl_sort(&stackset);
	print_stackset(&stackset);
	finl_stackset(&stackset);
}

// 5, 3, 2, 4, 0, 8, 9, 7, 6, 1

// 5, 4, 8, 9, 7, 6, 
// 1, 0, 2, 3, 


// |8, 9, 7, 6,|[(0) () ]
// |3| [(1,[


// 2,) (5, 4,)]

// 8, 9, 7, 6 |
// 0 | [(1, 2, 3,) (5, 4,)]

// 8, 9, 7, 6 |
// | [1, 0] | [(2, 3,) (5, 4,)]

// 8, 9|
// 7, 6| [1, 0] | [(2, 3,) (5, 4,)]

// (5, 4,) | 6, 7, 8, 9|
// (2, 3,) | [1, 0] |

// [4, 5] | 6, 7, 8, 9|
// [3, 2] | [1, 0] |
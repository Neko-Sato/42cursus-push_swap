#include "includes/push_swap.h"

int main()
{
	t_stack stackset[2];
	int q[] = {10, 0};

	setdata(&stackset, (int []){3, 1, 8, 2, 5, 4, 0, 6 ,7, 9}, 10);
	mixed_sort(stackset, &q[0]);
	fin_stackset(&stackset);
}

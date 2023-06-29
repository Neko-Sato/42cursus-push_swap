#include "includes/push_swap.h"

int main()
{
	t_stackset stackset;
	int q[] = {10, 0};

	setdata(&stackset, (int []){3, 1, 8, 2, 5, 4, 0, 6 ,7, 9}, 10);
	bisection_sort(&stackset, &q[0], &q[1]);
	fin_stackset(&stackset);
}

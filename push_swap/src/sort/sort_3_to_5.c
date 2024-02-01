#include "../inc/push_swap.h"

// Sorts three elements in stack A to achieve ascending order.
void	sort_three_elements(t_stacks *stacks)
{
	if (stacks->a[2] != 2)
	{
		if (stacks->a[0] == 2)
			rotate(stacks->a, stacks->a_size, "r", "a");
		else
			rotate(stacks->a, stacks->a_size, "rr", "a");
	}
	if (stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
}

// Sorts four to five elements using stacks A and B to achieve ascending order.
void	sort_four_or_five_elements(t_stacks *stacks)
{
	while (stacks->b_size <= 1)
	{
		if (stacks->a[0] == 0 || stacks->a[0] == 1)
			push("pb", stacks);
		else
			rotate(stacks->a, stacks->a_size, "r", "a");
	}
	if (stacks->b[0] == 0)
		swap("sb", stacks->b, stacks->b_size);
	if (stacks->a[2] != 4)
	{
		if (stacks->a[0] == 4)
			rotate(stacks->a, stacks->a_size, "r", "a");
		else
			rotate(stacks->a, stacks->a_size, "rr", "a");
	}
	if (stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
	push("pa", stacks);
	push("pa", stacks);
}

#include "../inc/push_swap.h"

// Performs radix sort on stack B based on the specified bit position.
static void	radix_sort_stack_b(t_stacks *stacks, int b_size,
							int max_bit_size, int j)
{
	while (b_size-- && j <= max_bit_size && !is_sorted(stacks))
	{
		if (((stacks->b[0] >> j) & 1) == 0)
			rotate(stacks->b, stacks->b_size, "r", "b");
		else
			push("pa", stacks);
	}
	if (is_sorted(stacks))
		while (stacks->b_size != 0)
			push("pa", stacks);
}

// Performs radix sort on stacks A and B using the most significant bit first.
void	radix_sort(t_stacks *stacks)
{
	int	j;
	int	max_bit_size;
	int	size;

	max_bit_size = 0;
	size = stacks->a_size;
	while (size > 1 && ++max_bit_size)
		size = size / 2;
	j = -1;
	while (++j <= max_bit_size)
	{
		size = stacks->a_size;
		while (size-- && !is_sorted(stacks))
		{
			if (((stacks->a[0] >> j) & 1) == 0)
				push("pb", stacks);
			else
				rotate(stacks->a, stacks->a_size, "r", "a");
		}
		radix_sort_stack_b(stacks, stacks->b_size, max_bit_size, j + 1);
	}
	while (stacks->b_size != 0)
		push("pa", stacks);
}

#include "../inc/push_swap.h"

// Pushes the top element from stack B to stack A (pa) or vice versa (pb).
void	push(char *str, t_stacks *stacks)
{
	int	aux;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (stacks->b_size <= 0)
			return ;
		aux = stacks->b[0];
		ft_memmove(stacks->a + 1, stacks->a, sizeof(int) * stacks->a_size);
		stacks->a[0] = aux;
		stacks->b_size--;
		ft_memmove(stacks->b, stacks->b + 1, sizeof(int) * stacks->b_size);
		stacks->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (stacks->a_size <= 0)
			return ;
		aux = stacks->a[0];
		ft_memmove(stacks->b + 1, stacks->b, sizeof(int) * stacks->b_size);
		stacks->b[0] = aux;
		stacks->a_size--;
		ft_memmove(stacks->a, stacks->a + 1, sizeof(int) * stacks->a_size);
		stacks->b_size++;
	}
	ft_putendl_fd(str, 1);
}

// Swaps the top two elements of the given array.
void	swap(char *str, int *array, int size)
{
	int	aux;

	if (size <= 0)
		return ;
	aux = array[0];
	array[0] = array[1];
	array[1] = aux;
	ft_putendl_fd(str, 1);
}

// Rotates the elements of the array based on the specified direction.
// For 'rr', rotates in reverse order (last element becomes the first).
void	rotate(int *array, int size, char *direction, char *list)
{
	int	aux;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "rr", 3) == 0)
	{
		aux = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = aux;
		write(1, "rr", 2);
	}
	else if (ft_strncmp(direction, "r", 2) == 0)
	{
		aux = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = aux;
		write(1, "r", 1);
	}
	ft_putendl_fd(list, 1);
}

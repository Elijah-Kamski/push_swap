#include "../inc/push_swap.h"

// Concatenates command-line arguments into a single space-separated string.
static void	join_args(int argc, char **argv, t_stacks *stacks)
{
	char	*aux;
	char	*aux2;
	int		i;

	i = 0;
	aux2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		aux = ft_strjoin(aux2, argv[i]);
		if (aux2)
			free(aux2);
		if (i != argc - 1)
		{
			aux2 = ft_strjoin(aux, " ");
			if (aux)
				free(aux);
			aux = aux2;
		}
	}
	stacks->join_args = ft_strdup(aux);
	if (stacks->join_args == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	if (aux)
		free(aux);
}

// Sorts elements in stack A based on its size using various sorting methods.
void	sort_elements(t_stacks *stacks)
{
	if (stacks->a_size == 2 && stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
	else if (stacks->a_size == 3)
		sort_three_elements(stacks);
	else if (stacks->a_size >= 4 && stacks->a_size <= 5)
		sort_four_or_five_elements(stacks);
	else
		radix_sort(stacks);
}

// Main function: validates arguments, initializes stacks,
// sorts, and checks results.
int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	validate_arguments(argc, argv);
	stacks = malloc(sizeof * stacks);
	if (stacks == NULL)
		exit(1);
	initialize_stacks(argc, argv, stacks);
	join_args(argc, argv, stacks);
	parse_numbers(stacks);
	exit_if_has_duplicate_or_is_sorted(stacks, 0);
	create_index(stacks);
	sort_elements(stacks);
	exit_if_has_duplicate_or_is_sorted(stacks, 1);
	free_and_exit_with_msg(stacks, "Error\n");
	return (0);
}

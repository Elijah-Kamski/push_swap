#include "../inc/push_swap.h"
// #include <limits.h>

// Converts a string to an integer, handling sign, overflow, and length checks.
static int	parse_atoi(const char *n, t_stacks *stacks)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_msg(stacks, "Error\n");
		res = res * 10 + (n[i++] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648
			|| ft_strlen(n) > 11)
			free_and_exit_with_msg(stacks, "Error\n");
	}
	return ((int)(res * sign));
}

// Parses space-separated numbers from the joined input arguments.
void	parse_numbers(t_stacks *stacks)
{
	char	**aux;
	int		i;
	int		z;

	z = 0;
	aux = ft_split(stacks->join_args, ' ');
	i = 0;
	while (aux[i] != NULL && aux[i][0] != '\0')
	{
		stacks->a[z++] = parse_atoi(aux[i++], stacks);
		free(aux[i - 1]);
	}
	free(aux);
}

// Initializes stacks, calculates sizes, allocates memory for stack arrays.
void	initialize_stacks(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			stacks->a_size += ft_count_words(argv[i + 1], ' ');
		else
			stacks->a_size++;
		i++;
	}
	stacks->a = malloc(stacks->a_size * sizeof * stacks->a);
	if (stacks->a == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	stacks->b = malloc(stacks->a_size * sizeof * stacks->b);
	if (stacks->b == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
}

// Creates an index array based on the order of elements in stack A.
void	create_index(t_stacks *stacks)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(stacks->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	i = -1;
	while (++i < stacks->a_size)
	{
		k = 0;
		j = -1;
		while (++j < stacks->a_size)
			if (stacks->a[i] > stacks->a[j])
				k++;
		new_a[i] = k;
	}
	i = stacks->a_size;
	while (i--)
		stacks->a[i] = new_a[i];
	free(new_a);
}

// Checks if stack A is sorted in ascending order.
int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

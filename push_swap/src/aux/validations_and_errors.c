#include "../inc/push_swap.h"

// Validates input arguments for correctness and potential errors.
void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_and_exit_with_msg(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			free_and_exit_with_msg(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_with_msg(NULL, "Error\n");
			j++;
		}
	}
}

// Frees allocated memory and exits the program with an optional error message.
void	free_and_exit_with_msg(t_stacks *stacks, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stacks != NULL)
	{
		if (stacks->a != NULL)
			free(stacks->a);
		if (stacks->b != NULL)
			free(stacks->b);
		if (stacks->join_args != NULL)
			free(stacks->join_args);
		if (stacks != NULL)
			free(stacks);
	}
	exit(1);
}

// Exits the program with an error if the stack is sorted or has duplicates.
void	exit_if_has_duplicate_or_is_sorted(t_stacks *stacks, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stacks->a_size)
		{
			j = i + 1;
			while (j < stacks->a_size)
			{
				if (stacks->a[i] == stacks->a[j])
					free_and_exit_with_msg(stacks, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_sorted(stacks))
		free_and_exit_with_msg(stacks, NULL);
}

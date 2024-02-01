#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

//***Handle errors
void		free_and_exit_with_msg(t_stacks *stacks, char *msg);
void		exit_if_has_duplicate_or_is_sorted(t_stacks *stacks, int i);
void		validate_arguments(int argc, char **argv);

//***Operations
void		push(char *str, t_stacks *stacks);
void		swap(char *str, int *array, int size);
void		rotate(int *array, int size, char *direction, char *list);

//***Sort Algorithm
void		sort_three_elements(t_stacks *stacks);
void		sort_four_or_five_elements(t_stacks *stacks);
void		radix_sort(t_stacks *stacks);

//***Stack Utils
void		parse_numbers(t_stacks *stacks);
void		create_index(t_stacks *stacks);
void		initialize_stacks(int argc, char **argv, t_stacks *stacks);
int			is_sorted(t_stacks *stacks);

#endif
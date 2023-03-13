#include "push_swap.h"
#include "linked_list.h"
#include "stacks/stacks.h"
#include "helper.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "short_stack_sorter.h"
#include "parser.h"
#include <stdio.h>
#include <unistd.h>

void	brute_force_sort(t_stacks *original, t_stacks *copy)
{
	int				min_steps;
	int				steps;
	t_parameters	min_params;
	t_parameters	params;

	params.offset = -original->size_a / 4 - 1;
	if (params.offset < -26)
		params.offset = -26;
	min_steps = __INT_MAX__;
	min_params = (t_parameters){};
	while (params.offset++ <= 25)
	{
		params.rate = 34;
		while (params.rate++ <= 50)
		{
			steps = natural_merge_sort(copy, params.offset, params.rate, 0);
			copy_stack(copy->stack_a, original->stack_a, original->size_a);
			if (min_steps > steps)
			{
				min_steps = steps;
				min_params = params;
			}
		}
	}
	natural_merge_sort(original, min_params.offset, min_params.rate, 1);
}

void	free_resources(t_stacks *original, t_stacks *copy)
{
	if (original != NULL)
		delete_linked_list(&(original->stack_a));
	if (copy != NULL)
		delete_linked_list(&(copy->stack_a));
}

int	end_program(t_stacks *original, t_stacks *copy, int exit_code)
{
	free_resources(original, copy);
	return (exit_code);
}

int	raise_error(t_stacks *original, t_stacks *copy)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (end_program(original, copy, 1));
}

int	main(int argc, char **argv)
{
	t_stacks	original;
	t_stacks	copy;

	if (argc == 1)
		return (end_program(NULL, NULL, 0));
	original = (t_stacks){};
	copy = (t_stacks){};
	original.stack_a = parser(argc - 1, argv + 1);
	copy.stack_a = parser(argc - 1, argv + 1);
	if (original.stack_a == NULL || copy.stack_a == NULL)
		return (raise_error(&original, &copy));
	original.size_a = len_linked_list(original.stack_a);
	copy.size_a = original.size_a;
	bubble_sort(&copy, 0);
	if (check_duplicates(&copy))
		return (raise_error(&original, &copy));
	if (is_stack_sorted(&original))
		return (end_program(&original, &copy, 0));
	replace_with_position(&original, &copy);
	copy_stack(copy.stack_a, original.stack_a, original.size_a);
	if (original.size_a <= 5)
		sort_short_stack(&copy, original.size_a, 1);
	else
		brute_force_sort(&original, &copy);
	return (end_program(&original, &copy, 0));
}

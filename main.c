#include "push_swap.h"
#include "linked_list.h"
#include "stacks.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "short_stack_sorter.h"
#include <stdio.h>
#include <unistd.h>

t_linked_list	*parser(int argc, char **argv)
{
	t_linked_list	*list;
	t_linked_list	*current;
	const char		*copy;
	const char		*list_number;
	int				digit;
	int				mult;

	list = new_node_linked_list(0);
	if (list == NULL)
		return (NULL);
	current = list;
	while (argc > 0)
	{
		list_number = *argv;
		while (*list_number)
		{
			mult = 1;
			copy = list_number;
			digit = 0;
			while (*list_number != ' ' && *list_number != '\0')
			{
				if (*list_number != '-' && (*list_number < '0' || *list_number > '9'))
				{
					delete_linked_list(&list);
					return (NULL);
				}
				digit++;
				list_number++;
			}
			while (digit > 0)
			{
				digit--;
				if (copy[digit] == '-')
					current->content = -current->content;
				else
				{
					current->content += (copy[digit] - '0') * mult;
					if (current->content < 0)
					{
						delete_linked_list(&list);
						return (NULL);
					}
				}
				mult = mult * 10;
			}
			if (*list_number != '\0')
				list_number++;
			current->next = new_node_linked_list(0);
			if (current->next == NULL)
			{
				delete_linked_list(&list);
				return (NULL);
			}
			current->next->previous = current;
			current = current->next;
		}
		argv++;
		argc--;
	}
	current = current->previous;
	delete_node_linked_list(current->next);
	current->next = list;
	list->previous = current;
	return (list);
}

void	replace_with_position(t_stacks *stacks, t_stacks *ordered)
{
	int				ordered_index;
	int				stacks_index;
	t_linked_list	*current_stack;
	t_linked_list	*current_ordered;

	stacks_index = 0;
	ordered_index = 0;
	current_stack = stacks->stack_a;
	current_ordered = ordered->stack_a;
	while (stacks_index < stacks->size_a)
	{
		while (current_ordered->content != current_stack->content)
		{
			current_ordered = current_ordered->next;
			ordered_index = (ordered_index + 1) % stacks->size_a;
		}
		current_stack->content = ordered_index;
		current_stack = current_stack->next;
		stacks_index++;
	}
}

void	copy_stack(t_linked_list *destination, t_linked_list *source, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		destination->content = source->content;
		destination = destination->next;
		source = source->next;
		index++;
	}
}

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

int	check_duplicates(t_stacks *stacks)
{
	int	index;

	if (stacks->size_a == 1)
		return (0);
	index = 0;
	while (index++ < stacks->size_a)
		if (stacks->stack_a->content == stacks->stack_a->next->content)
			return (1);
	return (0);
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

#include "stacks.h"
#include "helper.h"
#include <unistd.h>

int	is_stack_sorted(t_stacks *stacks)
{
	int				index;
	t_linked_list	*current;

	if (stacks->stack_b != NULL)
		return (0);
	index = 0;
	current = stacks->stack_a;
	while (index < stacks->size_a - 1)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
		index++;
	}
	return (1);
}

int	insert_top_b_into_a(t_stacks *stacks, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = get_distance(stacks->stack_a, stacks->size_a,
			stacks->stack_b->content);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps + 1;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(stacks, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(stacks, verbose);
	push_a(stacks, verbose);
	return (operations);
}

int	move_stack_a_to_zero(t_stacks *stacks, int verbose)
{
	int	distance;
	int	operations;
	int	steps;

	distance = find_element(stacks->stack_a, stacks->size_a, 0);
	steps = -distance * (distance < 0) + distance * (distance > 0);
	operations = steps;
	if (distance > 0)
		while (steps-- > 0)
			rotate_a(stacks, verbose);
	else
		while (steps-- > 0)
			reverse_rotate_a(stacks, verbose);
	return (operations);
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

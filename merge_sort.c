#include "stacks.h"
#include <unistd.h>

static int	get_distance(t_linked_list *stack, int size, int value)
{
	int	index;

	if (stack == NULL)
		return (0);
	if (stack->next == stack)
		return (0);
	index = 0;
	while ((value > stack->content || value < stack->previous->content)
		&& !(stack->content < stack->previous->content && value > stack->previous->content)
		&& !(stack->content < stack->previous->content && value < stack->content))
	{
		stack = stack->next;
		index++;
	}
	if (index > size / 2)
		return (index - size);
	return (index);
}

static int	find_element(t_linked_list *stack, int size, int value)
{
	int	index;

	index = 0;
	while (stack->content != value)
	{
		stack = stack->next;
		index++;
	}
	if (index > size / 2)
		return (index - size);
	return (index);
}

int	is_single_group(t_linked_list *node)
{
	t_linked_list	*last;

	if (node == NULL)
		return (1);
	if (node->content == node->next->content)
		return (1);
	last = node->previous;
	while (node != last)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	reverse_merge_natural_group_from_a_to_b(t_stacks *stacks, int verbose)
{
	int	stop_a;
	int	stop_b;
	int	operations;

	stop_a = stacks->size_a == 0;
	stop_b = stacks->size_b == 0;
	operations = 0;
	while (!stop_a || !stop_b)
	{
		operations++;
		if (!stop_b && (stop_a || stacks->stack_a->content > stacks->stack_b->previous->content))
		{
			stop_b = (stacks->size_b == 1 || stacks->stack_b->previous->content > stacks->stack_b->previous->previous->content);
			reverse_rotate_b(stacks, verbose);
		}
		else if (!stop_a && (stop_b || stacks->stack_a->content < stacks->stack_b->previous->content))
		{
			stop_a = (stacks->size_a == 1 || stacks->stack_a->content > stacks->stack_a->next->content);
			push_b(stacks, verbose);
		}
	}
	return (operations);
}

int	reverse_merge_natural_group_from_b_to_a(t_stacks *stacks, int verbose)
{
	int	stop_a;
	int	stop_b;
	int	operations;

	stop_a = stacks->size_a == 0;
	stop_b = stacks->size_b == 0;
	operations = 0;
	while (!stop_a || !stop_b)
	{
		operations++;
		if (!stop_a && (stop_b || stacks->stack_b->content < stacks->stack_a->previous->content))
		{
			stop_a = (stacks->size_a == 1 || stacks->stack_a->previous->content < stacks->stack_a->previous->previous->content);
			reverse_rotate_a(stacks, verbose);
		}
		else if (!stop_b && (stop_a || stacks->stack_b->content > stacks->stack_a->previous->content))
		{
			stop_b = (stacks->size_b == 1 || stacks->stack_b->content < stacks->stack_b->next->content);
			push_a(stacks, verbose);
		}
	}
	return (operations);
}

static int	apply_offset(t_stacks *stacks, int offset, int verbose)
{
	int	operations;

	if (offset > 0)
	{
		operations = offset;
		while (offset-- > 0)
			reverse_rotate_a(stacks, verbose);
		return (operations);
	}
	operations = -offset;
	while (offset++ < 0)
		rotate_a(stacks, verbose);
	return (operations);
}

static int	split_by_rate(t_stacks *stacks, int rate, int verbose)
{
	int	size;
	int	operations;

	size = rate * stacks->size_a / 100;
	operations = size;
	while (size-- > 0)
		push_b(stacks, verbose);
	return (operations);
}

static int	insert_top_b_into_a(t_stacks *stacks, int verbose)
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

static int	move_stack_a_to_zero(t_stacks *stacks, int verbose)
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

static int	merge_groups(t_stacks *stacks, int size, int verbose)
{
	int	operations;
	int	remaining;

	remaining = 0;
	while (stacks->size_a > size / 4)
		remaining += reverse_merge_natural_group_from_a_to_b(stacks, verbose);
	operations = remaining;
	if (is_single_group(stacks->stack_a))
		return (operations);
	remaining = stacks->size_b - remaining;
	if (remaining != stacks->size_b && remaining > 0)
	{
		operations += remaining;
		while (remaining-- > 0)
			reverse_rotate_b(stacks, verbose);
	}
	while (stacks->size_b > size / 2)
		operations += reverse_merge_natural_group_from_b_to_a(stacks, verbose);
	return (operations);
}

int	natural_merge_sort(t_stacks *stacks, int offset, int rate, int verbose)
{
	int	operations;
	int	size;

	size = stacks->size_a;
	operations = apply_offset(stacks, offset, verbose);
	operations += split_by_rate(stacks, rate, verbose);
	while (!is_single_group(stacks->stack_a))
		operations += merge_groups(stacks, size, verbose);
	while (stacks->size_b > 0)
		operations += insert_top_b_into_a(stacks, verbose);
	operations += move_stack_a_to_zero(stacks, verbose);
	return (operations);
}

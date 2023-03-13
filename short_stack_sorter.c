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
		&& !(stack->content < stack->previous->content
			&& value > stack->previous->content)
		&& !(stack->content < stack->previous->content
			&& value < stack->content))
	{
		stack = stack->next;
		index++;
	}
	if (index > size / 2)
		return (index - size);
	return (index);
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

void	sort_2_elements(t_stacks *stacks, int verbose)
{
	int	swapping_a;
	int	swapping_b;

	swapping_a = (stacks->size_a > 1
			&& stacks->stack_a->content > stacks->stack_a->next->content);
	swapping_b = (stacks->size_b > 1
			&& stacks->stack_b->content < stacks->stack_b->next->content);
	if (swapping_a && swapping_b)
		swap_both(stacks, verbose);
	else if (swapping_a)
		swap_a(stacks, verbose);
	else if (swapping_b)
		swap_b(stacks, verbose);
}

void	sort_3_elements(t_stacks *stacks, int verbose)
{
	if (stacks->stack_a->content == 1)
	{
		if (stacks->stack_a->next->content == 2)
			reverse_rotate_a(stacks, verbose);
		else if (stacks->stack_a->next->content == 0)
			swap_a(stacks, verbose);
	}
	else if (stacks->stack_a->content == 2)
	{
		if (stacks->stack_a->next->content == 0)
			rotate_a(stacks, verbose);
		else if (stacks->stack_a->next->content == 1)
		{
			swap_a(stacks, verbose);
			reverse_rotate_a(stacks, verbose);
		}
	}
	else if (stacks->stack_a->next->content == 2)
	{
		swap_a(stacks, verbose);
		rotate_a(stacks, verbose);
	}
}

void	sort_4_elements(t_stacks *stacks, int verbose)
{
	push_b(stacks, verbose);
	if (stacks->stack_a->content > stacks->stack_a->next->content
		&& stacks->stack_a->content > stacks->stack_a->previous->content)
	{
		if (stacks->stack_a->next->content > stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	}
	else if (stacks->stack_a->content > stacks->stack_a->next->content
		|| stacks->stack_a->content > stacks->stack_a->previous->content)
	{
		if (stacks->stack_a->next->content < stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	}
	else
		if (stacks->stack_a->next->content > stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	insert_top_b_into_a(stacks, verbose);
	move_stack_a_to_zero(stacks, verbose);
}

void	sort_5_elements(t_stacks *stacks, int verbose)
{
	push_b(stacks, verbose);
	push_b(stacks, verbose);
	if (stacks->stack_a->content > stacks->stack_a->next->content
		&& stacks->stack_a->content > stacks->stack_a->previous->content)
	{
		if (stacks->stack_a->next->content > stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	}
	else if (stacks->stack_a->content > stacks->stack_a->next->content
		|| stacks->stack_a->content > stacks->stack_a->previous->content)
	{
		if (stacks->stack_a->next->content < stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	}
	else
		if (stacks->stack_a->next->content > stacks->stack_a->previous->content)
			swap_a(stacks, verbose);
	insert_top_b_into_a(stacks, verbose);
	insert_top_b_into_a(stacks, verbose);
	move_stack_a_to_zero(stacks, verbose);
}

void	sort_short_stack(t_stacks *stacks, int size, int verbose)
{
	static void	(*sorter[4])(t_stacks *, int) = {
		&sort_2_elements,
		&sort_3_elements,
		&sort_4_elements,
		&sort_5_elements,
	};

	sorter[size - 2](stacks, verbose);
}

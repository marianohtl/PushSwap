#include "stacks/stacks.h"
#include "helper.h"
#include <unistd.h>

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

#include "stacks.h"
#include <unistd.h>

void	insertion_sort(t_stacks *stacks)
{
	int	is_sorted;
	int	index;
	int	total;

	is_sorted = is_stack_sorted(stacks);
	total = stacks->size_a;
	while (is_sorted == 0)
	{
		index = 0;
		while (index < total)
		{
			if (stacks->size_b > 0 && stacks->stack_b->content < stacks->stack_a->content)
			{
				push_b(stacks);
				rotate_a(stacks);
			}
			else if (stacks->stack_a->content > stacks->stack_a->next->content)
				push_a(stacks);
			else
				rotate_a(stacks);
			index++;
		}
		rotate_a(stacks);
		while (stacks->size_b > 0)
		{
			push_b(stacks);
			rotate_a(stacks);
		}
		is_sorted = is_stack_sorted(stacks);
	}
}

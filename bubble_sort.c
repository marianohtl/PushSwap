#include "stacks.h"
#include <unistd.h>

void	bubble_sort(t_stacks *stacks)
{
	int	is_sorted;
	int	index;

	is_sorted = is_stack_sorted(stacks);
	while (is_sorted == 0)
	{
		index = 0;
		while (index < stacks->size_a)
		{
			if (index < stacks->size_a - 1 && stacks->stack_a->content >= stacks->stack_a->next->content)
				swap_a(stacks);
			rotate_a(stacks);
			index++;
		}
		is_sorted = is_stack_sorted(stacks);
	}
}

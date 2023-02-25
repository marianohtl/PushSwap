#include "stacks.h"

void	bubble_sort(t_stacks *stacks)
{
	int	is_sorted;
	int	index;

	is_sorted = 0;
	while (is_sorted == 0)
	{
		index = 0;
		is_sorted = 1;
		while (index < stacks->size_a)
		{
			if (index < stacks->size_a - 1 && stacks->stack_a->content >= stacks->stack_a->next->content)
			{
				swap_a(stacks);
				is_sorted = 0;
			}
			rotate_a(stacks);
			index++;
		}
	}
}

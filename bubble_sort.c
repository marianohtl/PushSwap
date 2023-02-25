#include "stacks.h"
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

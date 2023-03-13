#include "stacks/stacks.h"
#include <unistd.h>

int	get_distance(t_linked_list *stack, int size, int value)
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

int	find_element(t_linked_list *stack, int size, int value)
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

	if (node == NULL || node->content == node->next->content)
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

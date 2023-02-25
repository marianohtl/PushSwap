#include "linked_list.h"
#include "stacks.h"
#include "bubble_sort.h"
#include <stdio.h>


void len_linked_list(t_linked_list *lst)
{
	t_linked_list *first;
	first = lst;

	int index;
	// int current;

	index = 1;
	
	lst = lst->next;
	while(lst != first)
	{
		index++;
		lst = lst->next;
	}
}

t_linked_list *parser(const char *list_number)
{
	t_linked_list	*list;
	t_linked_list	*current;
	const char *copy;
	int digit;
	int mult;
	
	list = new_node_linked_list(0);
	if (list == NULL)
		return (NULL);
	current = list;
	while (*list_number)
	{
		mult = 1;
		copy = list_number;
		digit = 0;
		while(*list_number != ' ' && *list_number != '\0')
		{
			digit++;
			list_number++;
		}
		while (digit > 0)
		{
			digit--;
			current->content += (copy[digit] - '0') * mult;
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
	current = current->previous;
	delete_node_linked_list(current->next);
	current->next = list;
	list->previous = current;
	return (list);
}

void	print_list(t_linked_list *list)
{
	t_linked_list *current;

	if (list == NULL)
	{
		dprintf(1, "%p\n", list);
		return ;
	}
	current = list;
	dprintf(1, "%d ", current->content);
	current = current->next;
	while (current != list && current != NULL)
	{
		dprintf(1, "%d ", current->content);
		current = current->next;
	}
	dprintf(1, "\n");
}

void	print_stacks(t_stacks *stacks)
{
	dprintf(1, "\e[33mA: ");
	print_list(stacks->stack_a);
	dprintf(1, "\e[32mB: ");
	print_list(stacks->stack_b);
	dprintf(1, "\e[0m");
}

int main(void )
{
	t_stacks	stacks;
	const char *test = "100 3 0 44 5 8";
	int	index;

	stacks.stack_a = parser(test);
	stacks.size_a = 6;
	stacks.stack_b = NULL;
	stacks.size_b = 0;
	dprintf(1, "Original\n");
	print_stacks(&stacks);
	dprintf(1, "\nSwap\n");
	swap_a(&stacks);
	print_stacks(&stacks);
	swap_a(&stacks);
	print_stacks(&stacks);
	dprintf(1, "\nRotate\n");
	rotate_a(&stacks);
	print_stacks(&stacks);
	dprintf(1, "\nReverse Rotate\n");
	reverse_rotate_a(&stacks);
	print_stacks(&stacks);

	dprintf(1, "\nPush\n");
	index = 0;
	while (index < 6)
	{
		index++;
		push_a(&stacks);
		print_stacks(&stacks);
	}
	dprintf(1, "\n");
	while (index > 0)
	{
		index--;
		push_b(&stacks);
		print_stacks(&stacks);
	}
	dprintf(1, "\n");
	bubble_sort(&stacks);
	print_stacks(&stacks);
	return 0;
}
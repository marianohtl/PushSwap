#include "linked_list.h"
#include "stacks.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include <stdio.h>


int len_linked_list(t_linked_list *lst)
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
	return (index);
}

t_linked_list *parser(int argc, char **argv)
{
	t_linked_list	*list;
	t_linked_list	*current;
	const char *copy;
	const char *list_number;
	int digit;
	int mult;
	
	list = new_node_linked_list(0);
	if (list == NULL)
		return (NULL);
	current = list;
	while (argc > 0)
	{
		list_number = *argv;
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
				if (copy[digit] == '-')
					current->content = -current->content;
				else
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
		argv++;
		argc--;
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

int main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = parser(argc - 1, argv + 1);
	stacks.size_a = len_linked_list(stacks.stack_a);
	stacks.stack_b = NULL;
	stacks.size_b = 0;
	insertion_sort(&stacks);
	return 0;
}
#include<stdio.h>
#include"linked_list.h"


void swap(t_linked_list *lst)
{
	int current;

	current = lst->content;

	lst->content = lst->next->content;
	lst->next->content = current;
}

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
/*
2 current
1
3
4
5  6

1 next
3
4  2
5  6
*/

void push(t_linked_list **list_a, t_linked_list **list_b)
{
	t_linked_list	*to_move;
	t_linked_list	*top;

	if (*list_a == NULL)
		return ;
	to_move = *list_a;
	if (to_move->next == to_move)
		*list_a = NULL;
	else
	{
		top = to_move->next;
		top->previous = to_move->previous;
		top->previous->next = top;
		*list_a = top;
	}
	if (*list_b == NULL)
	{
		*list_b = to_move;
		to_move->next = to_move;
		to_move->previous = to_move;
		return ;
	}
	to_move->next = *list_b;
	to_move->previous = (*list_b)->previous;
	(*list_b)->previous->next = to_move;
	*list_b = to_move;
}

void rotate(t_linked_list **lst)
{
	*lst = (*lst)->next;
}

void reverse_rotate(t_linked_list **lst)
{
	*lst = (*lst)->previous;
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
		printf("%p\n", list);
		return ;
	}
	current = list;
	printf("%d ", current->content);
	current = current->next;
	while (current != list && current != NULL)
	{
		printf("%d ", current->content);
		current = current->next;
	}
	printf("\n");
}

int main(void )
{
	t_linked_list	*list_a;
	const char *test = "100 3 0 44 5 8";
	t_linked_list	*list_b;
	int	index;

	list_a = parser(test);
	printf("Original\n");
	print_list(list_a);
	printf("\nSwap\n");
	swap(list_a);
	print_list(list_a);
	swap(list_a);
	print_list(list_a);
	printf("\nRotate\n");
	rotate(&list_a);
	print_list(list_a);
	printf("\nReverse Rotate\n");
	reverse_rotate(&list_a);
	print_list(list_a);

	printf("\nPush\n");
	list_b = NULL;
	index = 0;
	while (index < 6)
	{
		index++;
		push(&list_a, &list_b);
		printf("\e[33mA: ");
		print_list(list_a);
		printf("\e[32mB: ");
		print_list(list_b);
		
	}
	printf("\e[0m\n");
	while (index > 0)
	{
		index--;
		push(&list_b, &list_a);
		printf("\e[33mA: ");
		print_list(list_a);
		printf("\e[32mB: ");
		print_list(list_b);
	}
	printf("\e[0m\n");
	return 0;
}
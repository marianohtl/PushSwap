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
	int current;

	index = 1;
	
	lst = lst->next;
	while(lst != first)
	{
		index++;
		lst = lst->next;
	}
}

void rotate(t_linked_list **lst)
{
	*lst = (*lst)->next;
}

void reverse_rotate(t_linked_list **lst)
{
	*lst = (*lst)->previous;
}

void parser(int *converted_number, const char *list_number)
{
	const char *copy;
	int digit;
	int mult;
	int i;
	
	i = 0;
	while (*list_number)
	{
		converted_number[i] = 0;
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
			converted_number[i] += (copy[digit] - '0') * mult;
			mult = mult * 10;
		}
		list_number++;
		i++;
	}
}

int main(void )
{

	int converted_number[9999];
	//                     1↓
	const char *test = "100 3 0 44 5 8";
	//                     ↑
	parser(converted_number, test);
	printf("%d %d %d %d %d %d\n",converted_number[0], converted_number[1],converted_number[2],converted_number[3], converted_number[4], converted_number[5]);
	return 0;
}
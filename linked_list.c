#include "linked_list.h"
#include <stdlib.h>

t_linked_list	*new_node_linked_list(int content)
{
	t_linked_list	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

int	len_linked_list(t_linked_list *lst)
{
	int				index;
	t_linked_list	*first;

	first = lst;
	index = 1;
	lst = lst->next;
	while (lst != first)
	{
		index++;
		lst = lst->next;
	}
	return (index);
}

void	delete_node_linked_list(t_linked_list *node)
{
	free(node);
}

void	delete_linked_list(t_linked_list **linked_list)
{
	t_linked_list	*first;
	t_linked_list	*node;
	t_linked_list	*next;

	if (linked_list == NULL || *linked_list == NULL)
		return ;
	first = *linked_list;
	node = *linked_list;
	while (node->next != NULL && node->next != first)
	{
		next = node->next;
		delete_node_linked_list(node);
		node = next;
	}
	delete_node_linked_list(node);
}

int	append_linked_list(t_linked_list *node, t_linked_list *next)
{
	if (node == NULL || next == NULL)
		return (1);
	next->previous = node;
	node->next = next;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:54:35 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <unistd.h>

void	swap(t_linked_list *lst)
{
	int	current;

	current = lst->content;
	lst->content = lst->next->content;
	lst->next->content = current;
}

static void	insert_node(t_linked_list **lst, t_linked_list *node)
{
	(*lst)->previous->next = node;
	(*lst)->previous = node;
	*lst = node;
}

void	push(t_linked_list **list_a, t_linked_list **list_b)
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
	insert_node(list_b, to_move);
}

void	rotate(t_linked_list **lst)
{
	*lst = (*lst)->next;
}

void	reverse_rotate(t_linked_list **lst)
{
	*lst = (*lst)->previous;
}

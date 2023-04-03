/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:54:23 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <unistd.h>

static void	*failed_to_parse(t_linked_list **list)
{
	delete_linked_list(list);
	return (NULL);
}

static int	parse_number(t_linked_list *current, char **numbers)
{
	char	*copy;
	int		digit;
	int		mult;

	mult = 1;
	copy = *numbers;
	digit = 0;
	while (**numbers != ' ' && **numbers != '\0')
	{
		if (**numbers != '-' && (**numbers < '0' || **numbers > '9'))
			return (0);
		digit++;
		(*numbers)++;
	}
	while (digit-- > 0)
	{
		if (copy[digit] == '-')
			current->content = -current->content;
		else
			current->content += (copy[digit] - '0') * mult;
		if (copy[digit] != '-' && current->content < 0)
			return (0);
		mult = mult * 10;
	}
	return (1);
}

static t_linked_list	*close_list(t_linked_list *list, t_linked_list *last)
{
	last = last->previous;
	delete_node_linked_list(last->next);
	last->next = list;
	list->previous = last;
	return (list);
}

t_linked_list	*parser(int argc, char **argv)
{
	t_linked_list	*list;
	t_linked_list	*current;
	char			*list_number;

	list = new_node_linked_list(0);
	if (list == NULL)
		return (NULL);
	current = list;
	while (argc-- > 0)
	{
		list_number = *argv++;
		while (*list_number)
		{
			if (parse_number(current, &list_number) == 0)
				return (failed_to_parse(&list));
			current->next = new_node_linked_list(0);
			if (current->next == NULL)
				return (failed_to_parse(&list));
			current->next->previous = current;
			current = current->next;
			if (*list_number != '\0')
				list_number++;
		}
	}
	return (close_list(list, current));
}

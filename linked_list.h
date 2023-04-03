/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:54:53 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_linked_list	t_linked_list;
typedef struct s_linked_list
{
	t_linked_list	*previous;
	t_linked_list	*next;
	int				content;
}	t_linked_list;

int				append_linked_list(t_linked_list *node, t_linked_list *next);
void			delete_linked_list(t_linked_list **linked_list);
void			delete_node_linked_list(t_linked_list *node);
int				len_linked_list(t_linked_list *lst);
t_linked_list	*new_node_linked_list(int content);

#endif

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_linked_list	t_linked_list;
typedef struct s_linked_list
{
	t_linked_list	*previous;
	t_linked_list	*next;
	int				content;
}	t_linked_list;

t_linked_list	*new_linked_list(int content);

#endif

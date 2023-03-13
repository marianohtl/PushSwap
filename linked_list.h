#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_linked_list	t_linked_list;
typedef struct s_linked_list
{
	t_linked_list	*previous;
	t_linked_list	*next;
	int				content;
}	t_linked_list;

t_linked_list	*new_node_linked_list(int content);
int len_linked_list(t_linked_list *lst);
void	delete_node_linked_list(t_linked_list *node);
void	delete_linked_list(t_linked_list **linked_list);
int	append_linked_list(t_linked_list *node, t_linked_list *next);
t_linked_list	*new_linked_list(int *values, int elements);

#endif

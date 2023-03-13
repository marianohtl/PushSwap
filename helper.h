#ifndef HELPER_H
# define HELPER_H

int		check_duplicates(t_stacks *stacks);
void	copy_stack(t_linked_list *destination, t_linked_list *source, int size);
int		find_element(t_linked_list *stack, int size, int value);
int		get_distance(t_linked_list *stack, int size, int value);
int		is_single_group(t_linked_list *node);

#endif

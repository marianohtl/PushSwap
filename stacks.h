#ifndef STACKS_H
# define STACKS_H
# include "linked_list.h"

typedef struct s_stacks
{
	t_linked_list	*stack_a;
	t_linked_list	*stack_b;
	int				size_a;
	int				size_b;
}	t_stacks;

void	swap_a(t_stacks *stacks, int verbose);
void	swap_b(t_stacks *stacks, int verbose);
void	swap_both(t_stacks *stacks, int verbose);
void	push_a(t_stacks *stacks, int verbose);
void	push_b(t_stacks *stacks, int verbose);
void	rotate_a(t_stacks *stacks, int verbose);
void	rotate_b(t_stacks *stacks, int verbose);
void	rotate_both(t_stacks *stacks, int verbose);
void	reverse_rotate_a(t_stacks *stacks, int verbose);
void	reverse_rotate_b(t_stacks *stacks, int verbose);
void	reverse_rotate_both(t_stacks *stacks, int verbose);
int		is_stack_sorted(t_stacks *stacks);

#endif

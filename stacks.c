#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	swap_a(t_stacks *stacks)
{
	swap(stacks->stack_a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stacks *stacks)
{
	swap(stacks->stack_b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_both(t_stacks *stacks)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	push_a(t_stacks *stacks)
{
	push(&(stacks->stack_a), &(stacks->stack_b));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_stacks *stacks)
{
	push(&(stacks->stack_b), &(stacks->stack_a));
	write(STDOUT_FILENO, "pb\n", 3);
}

void	rotate_a(t_stacks *stacks)
{
	rotate(&(stacks->stack_a));
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_both(t_stacks *stacks)
{
	rotate(&(stacks->stack_a));
	rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "rr\n", 3);
}

void	reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	reverse_rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "rrr\n", 4);
}

#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	swap_a(t_stacks *stacks)
{
	swap(stacks->stack_a);
	write(STDOUT_FILENO, "SA\n", 3);
}

void	swap_b(t_stacks *stacks)
{
	swap(stacks->stack_b);
	write(STDOUT_FILENO, "SB\n", 3);
}

void	swap_both(t_stacks *stacks)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
	write(STDOUT_FILENO, "SS\n", 3);
}

void	push_a(t_stacks *stacks)
{
	push(&(stacks->stack_a), &(stacks->stack_b));
	write(STDOUT_FILENO, "PA\n", 3);
}

void	push_b(t_stacks *stacks)
{
	push(&(stacks->stack_b), &(stacks->stack_a));
	write(STDOUT_FILENO, "PB\n", 3);
}

void	rotate_a(t_stacks *stacks)
{
	rotate(&(stacks->stack_a));
	write(STDOUT_FILENO, "RA\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "RB\n", 3);
}

void	rotate_both(t_stacks *stacks)
{
	rotate(&(stacks->stack_a));
	rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "RR\n", 3);
}

void	reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	write(STDOUT_FILENO, "RRA\n", 4);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "RRB\n", 4);
}

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	reverse_rotate(&(stacks->stack_b));
	write(STDOUT_FILENO, "RRR\n", 4);
}

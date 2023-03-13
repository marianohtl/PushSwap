#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	rotate_a(t_stacks *stacks, int verbose)
{
	rotate(&(stacks->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks, int verbose)
{
	rotate(&(stacks->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_both(t_stacks *stacks, int verbose)
{
	rotate(&(stacks->stack_a));
	rotate(&(stacks->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rr\n", 3);
}

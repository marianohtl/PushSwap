#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	push_a(t_stacks *stacks, int verbose)
{
	push(&(stacks->stack_b), &(stacks->stack_a));
	stacks->size_a++;
	stacks->size_b--;
	if (verbose)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_stacks *stacks, int verbose)
{
	push(&(stacks->stack_a), &(stacks->stack_b));
	stacks->size_b++;
	stacks->size_a--;
	if (verbose)
		write(STDOUT_FILENO, "pb\n", 3);
}

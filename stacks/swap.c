/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:55:20 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	swap_a(t_stacks *stacks, int verbose)
{
	swap(stacks->stack_a);
	if (verbose)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stacks *stacks, int verbose)
{
	swap(stacks->stack_b);
	if (verbose)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_both(t_stacks *stacks, int verbose)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
	if (verbose)
		write(STDOUT_FILENO, "ss\n", 3);
}

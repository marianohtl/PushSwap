/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:55:26 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "operators.h"
#include <unistd.h>

void	reverse_rotate_a(t_stacks *stacks, int verbose)
{
	reverse_rotate(&(stacks->stack_a));
	if (verbose)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(t_stacks *stacks, int verbose)
{
	reverse_rotate(&(stacks->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	reverse_rotate_both(t_stacks *stacks, int verbose)
{
	reverse_rotate(&(stacks->stack_a));
	reverse_rotate(&(stacks->stack_b));
	if (verbose)
		write(STDOUT_FILENO, "rrr\n", 4);
}

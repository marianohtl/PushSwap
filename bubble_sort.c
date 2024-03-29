/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:55:10 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks/stacks.h"
#include <unistd.h>

void	bubble_sort(t_stacks *stacks, int verbose)
{
	int	is_sorted;
	int	index;

	is_sorted = is_stack_sorted(stacks);
	while (is_sorted == 0)
	{
		index = 0;
		while (index < stacks->size_a)
		{
			if (index < stacks->size_a - 1
				&& stacks->stack_a->content >= stacks->stack_a->next->content)
				swap_a(stacks, verbose);
			rotate_a(stacks, verbose);
			index++;
		}
		is_sorted = is_stack_sorted(stacks);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:55:22 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		insert_top_b_into_a(t_stacks *stacks, int verbose);
int		move_stack_a_to_zero(t_stacks *stacks, int verbose);
void	replace_with_position(t_stacks *stacks, t_stacks *ordered);

#endif

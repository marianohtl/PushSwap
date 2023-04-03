/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmariano <tmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:55:00 by tmariano          #+#    #+#             */
/*   Updated: 2023/04/03 00:56:19 by tmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

int		check_duplicates(t_stacks *stacks);
void	copy_stack(t_linked_list *destination, t_linked_list *source, int size);
int		find_element(t_linked_list *stack, int size, int value);
int		get_distance(t_linked_list *stack, int size, int value);
int		is_single_group(t_linked_list *node);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 16:08:51 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate_b(t_stack_bonus **stack)
{
	t_stack_bonus	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra_b(t_stack_bonus **a, bool write_mv)
{
	rev_rotate_b(a);
	if (!write_mv)
		write(1, "rra\n", 4);
}

void	rrb_b(t_stack_bonus **b, bool write_mv)
{
	rev_rotate_b(b);
	if (!write_mv)
		write(1, "rrb\n", 4);
}

void	rrr_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv)
{
	rev_rotate_b(a);
	rev_rotate_b(b);
	if (!write_mv)
		write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:08:45 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 14:15:16 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack_bonus **stack)
{
	t_stack_bonus	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra_b(t_stack_bonus **a, bool write_mv)
{
	rotate(a);
	if (!write_mv)
		write(1, "ra\n", 3);
}

void	rb_b(t_stack_bonus **b, bool write_mv)
{
	rotate(b);
	if (!write_mv)
		write(1, "rb\n", 3);
}

void	rr_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv)
{
	rotate(a);
	rotate(b);
	if (!write_mv)
		write(1, "rr\n", 3);
}

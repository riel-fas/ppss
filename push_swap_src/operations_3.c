/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:08:45 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 22:08:43 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool write_mv)
{
	rotate(a);
	if (!write_mv)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool write_mv)
{
	rotate(b);
	if (!write_mv)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool write_mv)
{
	rotate(a);
	rotate(b);
	if (!write_mv)
		write(1, "rr\n", 3);
}

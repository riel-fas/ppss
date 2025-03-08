/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:08:45 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 06:32:02 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool write_mv) //Rotate the top `a` node to the bottom of the stack, and write_mv the instruction
{
	rotate(a);
	if (!write_mv)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool write_mv) //Rotate the top `b` node to the bottom of the stack, and write_mv the instruction
{
	rotate(b);
	if (!write_mv)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool write_mv) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and write_mv the instruction
{
	rotate(a);
	rotate(b);
	if (!write_mv)
		write(1, "rr\n", 3);
}

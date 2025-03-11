/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:08:45 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 09:30:37 by riel-fas         ###   ########.fr       */
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

void	ra(t_stack_bonus **a)
{
	rotate(a);
}

void	rb(t_stack_bonus **b)
{
	rotate(b);
}

void	rr(t_stack_bonus **a, t_stack_bonus **b)
{
	rotate(a);
	rotate(b);
}

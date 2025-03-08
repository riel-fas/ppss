/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 06:32:19 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool write_mv) //Rotate the bottom of `a` to the top of the stack and write_mv the instruction
{
	rev_rotate(a);
	if (!write_mv)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool write_mv) //Rotate the bottom of `b` to the top of the stack and write_mv the instruction
{
	rev_rotate(b);
	if (!write_mv)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool write_mv) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (!write_mv)
		write(1, "rrr\n", 4);
}

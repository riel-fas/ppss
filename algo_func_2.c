/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:29:49 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 10:21:50 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}


static void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void sort_A_B(t_stack **a, t_stack **b)
{
	int	remaining_elements;

	remaining_elements = stack_length(*a);
	if (stack_sorted(*a))
		return;
	if (remaining_elements > 3)
	{
		pb(b, a, false);
		remaining_elements--;
	}
	if (remaining_elements > 3 && !stack_sorted(*a))
	{
		pb(b, a, false);
		remaining_elements--;
	}
    // Push elements from A to B until only 3 remain in A
	while (remaining_elements > 3 && !stack_sorted(*a)) {
		init_nodes_a(*a, *b);  // Prepare nodes for moving
		remaining_elements--;
    }
    // Move prepared elements from A to B
    move_a_to_b(a, b);
    // Sort the remaining three elements in stack A
    sort_the_three(a);
    // Move all elements from B back to A in sorted order
    while (*b) {
        init_nodes_b(*a, *b);  // Prepare nodes for moving
        move_b_to_a(a, b);
    }
    // Finalize the stack
    current_index(*a);  // Update indices after sorting
    min_on_top(a);      // Rotate stack A to put minimum value on top
}

// void	sort_A_B(t_stack **a, t_stack **b)
// {
// 	int	len_a; //To store the length of stack `a`

// 	len_a = stack_length(*a);
// 	if (len_a-- > 3 && !stack_sorted(*a))
// 		pb(b, a, false);
// 	if (len_a-- > 3 && !stack_sorted(*a))
// 		pb(b, a, false);
// 	{
// 		while (len_a-- > 3 && !stack_sorted(*a))
// 			init_nodes_a(*a, *b);
// 		move_a_to_b(a, b);
// 	}
// 	sort_the_three(a);
// 	while (*b)
// 	{
// 		init_nodes_b(*a, *b);
// 		move_b_to_a(a, b);
// 	}
// 	current_index(*a);
// 	min_on_top(a);
// }

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

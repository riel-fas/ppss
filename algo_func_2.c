/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:29:49 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 10:02:01 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
	rr(a, b, false); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
	rrr(a, b, false); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false);
}

static void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a`
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false);
}

static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
	if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
		ra(a, false);
	else
		rra(a, false);
}

void	sort_A_B(t_stack **a, t_stack **b)
{
	int len_a = stack_len(*a); // Get the length of stack `a`
	int count = 0; // Counter to track how many nodes have been processed

	if (len_a > 3 && !stack_sorted(*a))
	{
		pb(b, a, false); // Move one node from `a` to `b`
		count++; // Increment the counter
	}
	if (len_a - count > 3 && !stack_sorted(*a))
	{
		pb(b, a, false); // Move another node from `a` to `b`
		count++; // Increment the counter
	}
	while (len_a - count > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b); // Prepare nodes for sorting
		move_a_to_b(a, b);    // Move nodes from `a` to `b`
		count++; // Increment the counter
	}
	sort_three(a); // Sort the remaining 3 nodes in `a`
	while (*b)
	{
		init_nodes_b(*a, *b); // Prepare nodes for sorting
		move_b_to_a(a, b);    // Move nodes from `b` to `a`
	}
	current_index(*a); // Update node positions in `a`
	min_on_top(a);     // Ensure the smallest number is at the top of `a`
}








}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:53:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 16:44:05 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Append a node to the stack
static void send_nodes_to_a(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;

	if (!stack)
		return ;

	node = malloc(sizeof(t_stack));
	if (!node)
		return;
	node->nbr = n;
	node->next = NULL;
	node->cheap = 0;
	// node->prev = find_last(*stack);
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// Initialize stack A
void	populate_stack_a(t_stack **a, char **av, int start_index)
{
	long n;
	int i = start_index;

	while (av[i])
	{
		if (error_synt(av[i]))
		{
			free_stack(a);
			errors();
		}
		n = atoi_v2(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(a);
			errors();
		}
		if (error_dups(*a, (int)n))
		{
			free_stack(a);
			errors();
		}
		send_nodes_to_a(a, (int)n);//from long to int
		i++;
	}
}

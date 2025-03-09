/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:53:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 08:36:27 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void send_nodes_to_a(t_stack **stack, int n)
{
	t_stack	*node; //To store a pointer to the new node to be created with the value `n`
	t_stack	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheap = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->prev = last_node; //Update the previous pointer of the new node and complete the appending
	}
}

t_stack	*get_cheapest(t_stack *stack)
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

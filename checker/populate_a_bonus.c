/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_a_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:16:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 15:17:18 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	send_nodes_to_a(t_stack_bonus **stack, int n)
{
	t_stack_bonus	*node;
	t_stack_bonus	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_bonus));
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
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	populate_stack_a(t_stack_bonus **a, char **av)
{
	long	n;
	int		x;

	x = 0;
	while (av[x])
	{
		if (error_synt(av[x]))
		{
			free_stack(a);
			errors();
		}
		n = atoi_v2(av[x]);
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
		send_nodes_to_a(a, (int)n);
		x++;
	}
}

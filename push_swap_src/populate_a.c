/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:53:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 10:13:54 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_nodes_to_a(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

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
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

#include <stdio.h>
void populate_stack_a(t_stack **a, char **av) {
    long n;
    int x = 0;

    while (av[x]) {
        if (error_synt(av[x])) {
            free_stack(a);
            errors();
        }
        n = atoi_v2(av[x]);
        if (n == LONG_MAX || n == LONG_MIN || n > INT_MAX || n < INT_MIN) {
            printf("Overflow detected: %s\n", av[x]);
            free_stack(a);
            errors();
        }
        if (error_dups(*a, (int)n)) {
            free_stack(a);
            errors();
        }
        send_nodes_to_a(a, (int)n);
        x++;
    }
}





// void	populate_stack_a(t_stack **a, char **av)
// {
// 	long	n;
// 	int		x;

// 	x = 0;
// 	while (av[x])
// 	{
// 		if (error_synt(av[x]))
// 		{
// 			free_stack(a);
// 			errors();
// 		}
// 		n = atoi_v2(av[x]);
// 		if (n > INT_MAX || n < INT_MIN)
// 		{
// 			free_stack(a);
// 			errors();
// 		}
// 		if (error_dups(*a, (int)n))
// 		{
// 			free_stack(a);
// 			errors();
// 		}
// 		send_nodes_to_a(a, (int)n);
// 		x++;
// 	}
// }

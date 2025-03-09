/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:19:28 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 08:54:17 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

bool stack_sort_check(t_stack *stack)
{
    if (!stack || !stack->next)
        return true; // Empty or single-node stack is sorted
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return false;
        stack = stack->next;
    }
    return true;
}

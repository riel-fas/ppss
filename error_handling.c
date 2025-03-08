/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:45:57 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 06:27:27 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check for syntax errors in the input
int	error_synt(char *str)
{
	int x;

	x = 0;
	if (!(str[x] == '+' || str[x] == '-' || (str[x] >= '0' && str[x] <= '9')))
		return 1;
	if ((str[x] == '+' || str[x] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return 1;
	while (str[x])
	{
		if (!(*str >= '0' && *str <= '9'))
			return 1;
		x++;
	}
	return 0;
}

int	error_dups(t_stack *a, int n)
{
	if (!a)
		return 0;
	while (a)
	{
		if (a->nbr == n)
			return 1;
		a = a->next;
	}
	return 0;
}

// Free the entire stack
void	free_stack(t_stack **stack)
{
	t_stack *tmp;
	t_stack *current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

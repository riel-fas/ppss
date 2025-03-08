/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:45:57 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 16:50:15 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check for syntax errors in the input
int	error_synt(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
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

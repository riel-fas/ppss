/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:54:17 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 15:03:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_length(t_stack_bonus *stack)
{
	int	x;

	x = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		x++;
	}
	return (x);
}

t_stack_bonus	*find_last_node(t_stack_bonus *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_bonus *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_bonus	*find_min_nb(t_stack_bonus *stack)
{
	long	min;
	t_stack_bonus	*min_nb;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_nb = stack;
		}
		stack = stack->next;
	}
	return (min_nb);
}

t_stack_bonus	*find_max_nb(t_stack_bonus *stack)
{
	long	max;
	t_stack_bonus	*max_nb;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_nb = stack;
		}
		stack = stack->next;
	}
	return (max_nb);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 23:42:26 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_arguments(int ac, char **av, t_stack **a)
{
	char	**split_args;

	if (ac == 2)
	{
		split_args = split_v2(av[1], 32);
		populate_stack_a(a, split_args + 1);
		free_args(split_args);
	}
	else
		populate_stack_a(a, av + 1);
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_length(*a) == 2)
		sa(a, false);
	else if (stack_length(*a) == 3)
		sort_the_three(a);
	else
		sort_a_b(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments(ac, av, &a);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}

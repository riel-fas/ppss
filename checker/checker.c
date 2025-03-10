/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 16:26:04 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	handle_arguments_bonus(int ac, char **av, t_stack_bonus **a)
{
	char **splited;

	if (ac == 2)
	{
		splited = split_v2(av[1], 32);
		populate_stack_a(a, splited + 1);
		free_args(splited);
	}
	else
		populate_stack_a(a, av + 1);
}

int main(int ac, char **av)
{
	t_stack_bonus	*a;
	t_stack_bonus	*b;


	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments_bonus(ac, av, &a);
	if (stack_sorted(a))
	{
		write(1, "OK\n", 3);
		exit (EXIT_SUCCESS);
	}
	

	// if (!stack_sorted)
}

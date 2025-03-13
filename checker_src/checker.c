/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/12 12:56:27 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		errors();
}

void	check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line && line[0])
		oper_check(a, b, line);
}

static void	handle_arguments_bonus(int ac, char **av, t_stack_bonus **a)
{
	char	**splited;

	if (ac == 2)
	{
		splited = split_v2(av[1], 32);
		populate_stack_a(a, splited + 1);
		free_args(splited);
	}
	else
		populate_stack_a(a, av + 1);
}

int	main(int ac, char **av)
{
	t_stack_bonus	*a;
	t_stack_bonus	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments_bonus(ac, av, &a);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_moves(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (b)
		write(1, "KO\n", 3);
	else if (!stack_sorted(a))
		write(1, "KO\n", 3);
	else if (stack_sorted(a))
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

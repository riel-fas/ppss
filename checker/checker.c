/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 14:39:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b')
		sb(b);
	else if (line[0] == 's' && line[1] == 's')
		ss(a, b);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r')
		rr(a, b);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(b, a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b);
	else
		errors();
}

void	check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line && line[0] && (line[3] = '\n' || line[4] == '\n'))
		oper_check(a, b, line);
}

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
	char *line;
	int fd;

	a = NULL;
	b = NULL;
	fd = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments_bonus(ac, av, &a);
	while ((line = get_next_line(fd)) != NULL)
	{
		check_moves(&a, &b, line);
		free(line);
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

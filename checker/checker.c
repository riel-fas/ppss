/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 11:52:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(b, a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		rrb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		rrr(a, b);
	else
		errors();
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
	handle_arguments_bonus(ac, av, &a);//populate a init
	line  = get_next_line(fd);
	check_moves(&a, &b, line);
	// if (!line && !stack_sorted(a))
	// 	write (1, "KO\n", 3);
	// else if (!line && stack_sorted(a))
	// 	write (1, "OK\n", 3);

	free_stack(&a);
	free_stack(&b);

	// if (!stack_sorted)

	//we use gnl to get line by line
	//we check if every line is corresponding to any operations
	//if not retunr an error
	//after checking the moves , if they are good we check them by using them all on the given numbers
	//then we check if those numbers are sorted after that
	//if yes retun OK if no retunr KO
	//
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 08:53:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa_b(a)


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
	line  = get_next_line(fd);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_arguments_bonus(ac, av, &a);
	if (stack_sorted(a))
	{
		write(1, "OK\n", 3);
		exit (EXIT_SUCCESS);
	}
	else if (!stack_sorted(a))
	{

	}
	// if (!stack_sorted)

	//we use gnl to get line by line
	//we check if every line is corresponding to any operations
	//if not retunr an error
	//after checking the moves , if they are good we check them by using them all on the given numbers
	//then we check if those numbers are sorted after that
	//if yes retun OK if no retunr KO
	//
}

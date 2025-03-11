/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 16:18:41 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// static void	oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line)
// {
// 	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
// 		sa(a);
// 	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
// 		sb(b);
// 	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
// 		ss(a, b);
// 	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
// 		ra(a);
// 	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
// 		rb(b);
// 	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
// 		rr(a, b);
// 	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
// 		pa(a, b);
// 	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
// 		pb(b, a);
// 	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
// 		rra(a);
// 	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
// 		rrb(b);
// 	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
// 		rrr(a, b);
// 	else
// 		errors();
// }

// void	check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line)
// {
// 	if (line && line[0])
// 		oper_check(a, b, line);
// }

void    check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
    if (line && *line != '\0')
    {
        check_swap(a, b, line);
        check_reverse_rotate(a, b, line);
        check_rotate(a, b, line);
		check_push(a, b,line);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:50:12 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 16:01:55 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void  check_swap(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
}

void  check_rotate(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
 	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
}

void  check_reverse_rotate(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
    if (line[2] == 'a' && line[3] == '\n')
        rra(a);
    else if (line[2] == 'b' && line[3] == '\n')
        rrb(b);
    else if (line[2] == 'r' && line[3] == '\n')
        rrr(a, b);
}

void	check_push(t_stack_bonus **a, t_stack_bonus **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(b, a);
}
void  move_errors(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

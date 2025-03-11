/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:56:59 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 11:53:16 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line)
{

	// char *tmp;

	if (line)
	{
		oper_check(a, b, line);
		// free(tmp);
	}
	if(*b)
		write(1, "KO\n", 3);
	else if(!stack_sorted(*a))
		write(1, "KO\n", 3);
	else if(stack_sorted(*a))
		write(1, "OK\n", 3);
	free(line);
}

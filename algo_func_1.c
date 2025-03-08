/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:50 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 09:34:05 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

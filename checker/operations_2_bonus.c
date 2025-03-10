/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:07 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 14:14:41 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack_bonus **dst, t_stack_bonus **src)
{
	t_stack_bonus	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv)
{
	push(a, b);
	if (!write_mv)
		write(1, "pa\n", 3);
}

void	pb_b(t_stack_bonus **b, t_stack_bonus **a, bool write_mv)
{
	push(b, a);
	if (!write_mv)
		write(1, "pb\n", 3);
}

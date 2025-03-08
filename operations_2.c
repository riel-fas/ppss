/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:49:07 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 06:32:09 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

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
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool write_mv) //Push on top of `b`, the top `a` and write_mv the instruction
{
	push(a, b);
	if (!write_mv)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool write_mv) //Push on top of `a`, the top `b` and write_mv the instruction
{
	push(b, a);
	if (!write_mv)
		write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:11:34 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 08:38:52 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool write_mv)
{
	swap(a);
	if (!write_mv)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool write_mv)
{
	swap(b);
	if (!write_mv)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool write_mv)
{
	swap(a);
	swap(b);
	if (!write_mv)
		write(1, "ss\n", 3);
}

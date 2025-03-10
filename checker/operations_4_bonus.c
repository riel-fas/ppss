/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:11:34 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/10 14:16:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack_bonus **head)
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

void	sa_b(t_stack_bonus	**a, bool write_mv)
{
	swap(a);
	if (!write_mv)
		write(1, "sa\n", 3);
}

void	sb_b(t_stack_bonus **b, bool write_mv)
{
	swap(b);
	if (!write_mv)
		write(1, "sb\n", 3);
}

void	ss_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv)
{
	swap(a);
	swap(b);
	if (!write_mv)
		write(1, "ss\n", 3);
}

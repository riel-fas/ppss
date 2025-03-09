/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 16:18:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// static void print_stack(t_stack *stack, const char *name)
// {
//         printf("%s: ", name);
//         while (stack) {
//                 printf("%d ", stack->nbr);
//                 stack = stack->next;
//         }
//         printf("\n");
// }
	// printf("Initial stack A:\n");
    // print_stack(a, "A");

int main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return 1;
	if (argc == 2)
	{
		// argv = ft_split(argv[1], 32);
		argv = split_v2(argv[1], 32);
	}
	populate_stack_a(&a, argv + 1);

	if (!stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_the_three(&a);
		else
			sort_A_B(&a, &b);
	}
	free_stack(&a);
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 11:56:17 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void print_stack(t_stack *stack, const char *name)
{
        printf("%s: ", name);
        while (stack) {
                printf("%d ", stack->nbr);
                stack = stack->next;
        }
        printf("\n");
}

int main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	return 1;
	if (argc == 2)
		argv = split(argv[1], ' ');
	populate_stack_a(&a, argv, 1);
	printf("Initial stack A:\n");
    print_stack(a, "A");

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
    // free_stack(&b);
	return 0;
}
// ./push_swap 16 45 42 38 34 50 29 23 24 26 15 18 21 37 32 25 11 49 2 9 47 40 46 48 27 22 39 30 28 20 13 36 12 10 44 6 1 3 33 7 19 41 14 43 31 17 8 5 4 35
lelelelelelelellelelelellel
anananan

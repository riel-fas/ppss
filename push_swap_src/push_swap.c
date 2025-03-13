/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 09:53:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_arguments(int ac, char **av, t_stack **a) {
    char **split_args;
    char *joined_args;
    int total_len = 0;
    int i;

    if (ac == 1 || (ac == 2 && !av[1][0])) {
        errors();
    }

    for (i = 1; i < ac; i++) {
        total_len += strlen(av[i]) + 1; // +1 for space or null terminator
    }

    joined_args = malloc(total_len * sizeof(char));
    if (!joined_args) {
        errors();
    }

    joined_args[0] = '\0'; // Initialize as empty string
    for (i = 1; i < ac; i++) {
        strcat(joined_args, av[i]);
        if (i < ac - 1) {
            strcat(joined_args, " ");
        }
    }

    split_args = split_v2(joined_args, ' ');
    free(joined_args);

    if (!split_args || !split_args[0]) {
        errors();
    }

    populate_stack_a(a, split_args);
    free_args(split_args);
}




// static void	handle_arguments(int ac, char **av, t_stack **a)
// {
// 	char	**split_args;

// 	if (ac == 2)
// 	{
// 		split_args = split_v2(av[1], 32);
// 		populate_stack_a(a, split_args + 1);
// 		free_args(split_args);
// 	}
// 	else
// 		populate_stack_a(a, av + 1);
// }

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_length(*a) == 2)
		sa(a, false);
	else if (stack_length(*a) == 3)
		sort_the_three(a);
	else
		sort_a_b(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac < 2)
		return(0);

	handle_arguments(ac, av, &a);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}


// int main(int ac, char **av)
// {
//     t_stack *a = NULL;
//     t_stack *b = NULL;

//     if (ac == 1 || (ac == 2 && !av[1][0]))
//         return 1;

//     handle_arguments(ac, av, &a);

//     /* For demonstration, sort only if not already sorted */
//     if (!stack_sorted(a))
//     {
//         if (stack_length(a) == 2)
//             sa(&a, 0);
//         else if (stack_length(a) == 3)
//             sort_the_three(&a);
//         else
//             sort_a_b(&a, &b);
//     }
//     // print_stack(a);
//     free_stack(&a);
//     return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 15:24:30 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_total_length(int ac, char **av)
{
	int	total_len;
	int	i;
	int	x;

	i = 1;
	x = 0;
	total_len = 0;
	while (i < ac)
	{
		x = 0;
		while (av[i][x] != '\0')
		{
			total_len++;
			x++;
		}
		total_len++;
		i++;
	}
	return (total_len);
}

static char	*join_arguments(int ac, char **av, int total_len)
{
	char	*joined_args;
	char	*ptr;
	int		i;
	int		x;

	i = 1;
	joined_args = malloc(total_len * sizeof(char));
	if (!joined_args)
		errors();
	ptr = joined_args;
	while (i < ac)
	{
		x = 0;
		while (av[i][x] != '\0')
			*ptr++ = av[i][x++];
		if (i < ac - 1)
			*ptr++ = ' ';
		i++;
	}
	*ptr = '\0';
	return (joined_args);
}

void	handle_arguments(int ac, char **av, t_stack **a)
{
	char	*joined_args;
	char	**split_args;
	int		total_len;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		errors();
	total_len = calculate_total_length(ac, av);
	joined_args = join_arguments(ac, av, total_len);
	split_args = split_v2(joined_args, ' ');
	free(joined_args);
	if (!split_args || !split_args[0])
		errors();
	populate_stack_a(a, split_args);
	free_args(split_args);
}

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
		return (0);
	handle_arguments(ac, av, &a);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}

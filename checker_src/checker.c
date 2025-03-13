/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:42:21 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 18:22:48 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	handle_arguments_bonus(int ac, char **av, t_stack_bonus **a)
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

int	main(int ac, char **av)
{
	t_stack_bonus	*a;
	t_stack_bonus	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	handle_arguments_bonus(ac, av, &a);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_moves(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (b)
		write(1, "KO\n", 3);
	else if (!stack_sorted(a))
		write(1, "KO\n", 3);
	else if (stack_sorted(a))
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

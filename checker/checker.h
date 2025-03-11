/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:56:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 18:29:28 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/get_next_line/get_next_line.h"

typedef struct s_stack_bonus
{
	int						nbr;
	struct s_stack_bonus	*prev;
	struct s_stack_bonus	*next;
	bool					cheap;

}		t_stack_bonus;

void			rra(t_stack_bonus **a);
void			rrb(t_stack_bonus **b);
void			rrr(t_stack_bonus **a, t_stack_bonus **b);
void			pa(t_stack_bonus **a, t_stack_bonus **b);
void			pb(t_stack_bonus **b, t_stack_bonus **a);
void			ra(t_stack_bonus **a);
void			rb(t_stack_bonus **b);
void			rr(t_stack_bonus **a, t_stack_bonus **b);
void			sa(t_stack_bonus	**a);
void			sb(t_stack_bonus **b);
void			ss(t_stack_bonus **a, t_stack_bonus **b);
int				ft_strcmp(char *s1, char *s2);
bool			stack_sorted(t_stack_bonus *stack);
t_stack_bonus	*find_last_node(t_stack_bonus *stack);
int				stack_length(t_stack_bonus *stack);
void			free_args(char **args);
char			**split_v2(char *s, char c);
long			atoi_v2(char *s);
void			errors(void);
void			free_stack(t_stack_bonus **stack);
int				error_dups(t_stack_bonus *a, int n);
int				error_synt(char *str_n);
void			populate_stack_a(t_stack_bonus **a, char **av);
void			check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line);

#endif

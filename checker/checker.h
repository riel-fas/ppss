/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:56:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 11:52:40 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "../libft/get_next_line/get_next_line.h"

typedef	struct s_stack_bonus
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


bool			stack_sorted(t_stack_bonus *stack);
t_stack_bonus	*find_last_node(t_stack_bonus *stack);
t_stack_bonus	*find_min_nb(t_stack_bonus *stack);
t_stack_bonus	*find_max_nb(t_stack_bonus *stack);
int				stack_length(t_stack_bonus *stack);
void			free_args(char **args);

char			**split_v2(char *s, char c);
long			atoi_v2(char *s);

void			errors(void);
void			free_stack(t_stack_bonus **stack);
int				error_dups(t_stack_bonus *a, int n);
int				error_synt(char *str_n);


void			populate_stack_a(t_stack_bonus **a, char **av);

void			oper_check(t_stack_bonus **a, t_stack_bonus **b, char *line);
void			check_moves(t_stack_bonus **a, t_stack_bonus **b, char *line);






#endif

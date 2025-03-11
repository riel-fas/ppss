/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:56:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 08:37:39 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "../get_next_line/get_next_line.h"

typedef	struct s_stack_bonus
{
	int						nbr;
	struct s_stack_bonus	*prev;
	struct s_stack_bonus	*next;
	bool					cheap;

}		t_stack_bonus;

void			rra_b(t_stack_bonus **a, bool write_mv);
void			rrb_b(t_stack_bonus **b, bool write_mv);
void			rrr_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv);

void			pa_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv);
void			pb_b(t_stack_bonus **b, t_stack_bonus **a, bool write_mv);

void			ra_b(t_stack_bonus **a, bool write_mv);
void			rb_b(t_stack_bonus **b, bool write_mv);
void			rr_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv);

void			sa_b(t_stack_bonus	**a, bool write_mv);
void			sb_b(t_stack_bonus **b, bool write_mv);
void			ss_b(t_stack_bonus **a, t_stack_bonus **b, bool write_mv);


int				stack_length(t_stack_bonus *stack);
t_stack_bonus	*find_last_node(t_stack_bonus *stack);
bool			stack_sorted(t_stack_bonus *stack);
t_stack_bonus	*find_min_nb(t_stack_bonus *stack);
t_stack_bonus	*find_max_nb(t_stack_bonus *stack);
void			free_args(char **args);

char			**split_v2(char *s, char c);
long			atoi_v2(char *s);

void			errors(void);
void			free_stack(t_stack_bonus **stack);
int				error_dups(t_stack_bonus *a, int n);
int				error_synt(char *str_n);


void			populate_stack_a(t_stack_bonus **a, char **av);






#endif

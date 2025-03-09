/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:05 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 16:32:13 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

// Stack node structure
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				index;              // Index of the node in the stack
	bool			above_median;      // Whether the node is above the median
	int				push_cost;          // Cost to push the node to the correct position
	bool			cheap;          // Whether the node is the cheapest to push
	struct s_stack	*target_node; // Pointer to the target node in stack A
} t_stack;

// Error handling
void		errors(void);
void		free_stack(t_stack **stack);
int			error_dups(t_stack *a, int n);
int			error_synt(char *str);

// Stack operations
void		rra(t_stack **a, bool write_mv);
void		rrb(t_stack **b, bool write_mv);
void		rrr(t_stack **a, t_stack **b, bool write_mv);
void		pa(t_stack **a, t_stack **b, bool write_mv);
void		pb(t_stack **b, t_stack **a, bool write_mv);
void		ra(t_stack **a, bool write_mv);
void		rb(t_stack **b, bool write_mv);
void		rr(t_stack **a, t_stack **b, bool write_mv);
void		ss(t_stack **a, t_stack **b, bool write_mv);
void		sb(t_stack **b, bool write_mv);
void		sa(t_stack	**a, bool write_mv);

// Stack utilities
int			stack_length(t_stack *stack);
t_stack		*find_last(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
bool		stack_sorted(t_stack *stack);

// Sorting algorithms
void		populate_stack_a(t_stack **a, char **av);
void		sort_the_three(t_stack **a);
void		sort_A_B(t_stack **a, t_stack **b);

// Cost-based approach
void		current_index(t_stack *stack);
void		set_target_b(t_stack *a, t_stack *b);
void		cost_analysis_b(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *stack);
t_stack		*get_cheapest(t_stack *stack);
void		move_to_top(t_stack **stack, t_stack *target);
void		init_nodes_a(t_stack *a, t_stack *b);
void		init_nodes_b(t_stack *a, t_stack *b);
void		prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

// Input parsing
//
char **split_v2(char *s, char c);
long		atoi_v2(`char *av);



#endif

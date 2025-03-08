/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:10:05 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/08 10:02:53 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

// Stack node structure
typedef struct s_stack
{
    int nbr;                // Value stored in the node
    struct s_stack *prev;   // Pointer to the previous node
    struct s_stack *next;   // Pointer to the next node
    int index;              // Index of the node in the stack
    bool above_median;      // Whether the node is above the median
    int push_cost;          // Cost to push the node to the correct position
    bool cheap;          // Whether the node is the cheapest to push
    struct s_stack *target_node; // Pointer to the target node in stack A
} t_stack;

// Error handling
void	errors(void);
void	free_stack(t_stack **stack);
int		error_dups(t_stack **a, int n);
int		error_synt(char *str);

// Stack operations
void	rra(t_stack **a, bool write_mv);
void	rrb(t_stack **b, bool write_mv);
void	rrr(t_stack **a, t_stack **b, bool write_mv);
void	pa(t_stack **a, t_stack **b, bool write_mv);
void	pb(t_stack **b, t_stack **a, bool write_mv);
void	ra(t_stack **a, bool write_mv);
void	rb(t_stack **b, bool write_mv);
void	rr(t_stack **a, t_stack **b, bool write_mv);
void	ss(t_stack **a, t_stack **b, bool write_mv);
void	sb(t_stack **b, bool write_mv);
void	sa(t_stack	**a, bool write_mv);

// Stack utilities
int stack_length(t_stack *stack);
t_stack *find_last(t_stack *stack);
bool stack_sorted(t_stack *stack);
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);

// Sorting algorithms
void	sort_the_three(t_stack **a);
void	sort_A_B(t_stack **a, t_stack **b);



void push_nodes_to_b(t_stack **a, t_stack **b);
void sort_three(t_stack **a);
void sort_stack_b(t_stack **b);
void push_back_to_a(t_stack **a, t_stack **b);
void final_adjustments(t_stack **a);

// Cost-based approach
void current_index(t_stack *stack);
void set_target_b(t_stack *a, t_stack *b);
void cost_analysis_b(t_stack *a, t_stack *b);
void set_cheapest(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);
void move_to_top(t_stack **stack, t_stack *target);

// Input parsing
char **split(char *s, char c);
long atoi_v2(char *av);
void populate_stack_a(t_stack **a, char **av, int start_index);

#endif

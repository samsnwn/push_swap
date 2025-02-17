/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:16:52 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 18:15:06 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack_node
{
	int					num;
	int					pos;
	int					cost;
	int					upper_half;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Parsing
int						*parse_args(int argc, char **argv, int *size,
							int *is_split);
int						*convert_to_int_array(char **argv, int size,
							int *error);
t_stack_node			*create_stack_from_array(int *numbers, int size);
int						check_duplicates(int *numbers, int size);

//*** Handle errors-free ***
void					free_args(char **argv);
void					free_stack(t_stack_node **stack);
void					number_free(int *numbers, int *error);
int						error_syntax(char *str_nbr);

// complex sort
void					push_to_b(t_stack_node **src, t_stack_node **dst,
							int count);
void					update_positions(t_stack_node *stack);
void					set_target_nodes(t_stack_node *a, t_stack_node *b);
void					calculate_costs(t_stack_node *a, t_stack_node *b);
t_stack_node			*find_best_move(t_stack_node *b);
int						get_target_cost(t_stack_node *node, int len_a,
							int len_b);
void					do_rotations(t_stack_node **a, t_stack_node **b,
							t_stack_node *node);
void					rotate_to_min(t_stack_node **stack);

// node utils
t_stack_node			*find_highest(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);

//*** linked list utils ***
int						stack_sorted(t_stack_node *stack);
int						stack_size(t_stack_node *stack);
int						count_numbers(char **argv);

//*** Algorithms ***
void					sort_stack(t_stack_node **a, t_stack_node **b,
							int size);
void					sort_three(t_stack_node **a);
void					sort_large_stack(t_stack_node **a, t_stack_node **b);

//*** Operations ***
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);

#endif

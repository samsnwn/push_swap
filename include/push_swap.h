/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:16:52 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 14:16:55 by samcasti         ###   ########.fr       */
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
	int					idx;
	int					cost;
	int					upper_half;
	int					is_optimal;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Parsing
int						*parse_args(int argc, char **argv, int *size,
							int *is_split);
int						*convert_to_int_array(char **argv, int size,
							int *error);
int						check_duplicates(int *numbers, int size);
t_stack_node			*create_stack_from_array(int *numbers, int size);

//*** Handle errors-free ***
void					free_args(char **argv);
void					error_free(t_stack_node **a, char **argv,
							int flag_argc_2);
void					free_stack(t_stack_node **stack);
int						error_repetition(t_stack_node *a, int nbr);
int						error_syntax(char *str_nbr);
void					handle_input_error(int *numbers, char **argv,
							int is_split);

// complex utils
void					update_positions(t_stack_node *stack);
void					execute_optimal_rotations(t_stack_node **a,
							t_stack_node **b, t_stack_node *node);
void					complete_rotation(t_stack_node **stack,
							t_stack_node *top, char stack_id);
void					execute_move(t_stack_node **a, t_stack_node **b);
void					calculate_move_costs(t_stack_node *a, t_stack_node *b);
void					find_optimal_target(t_stack_node *a, t_stack_node *b);
void					mark_cheapest_move(t_stack_node *b);

// node utils
t_stack_node			*find_highest(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
void					prepare_nodes(t_stack_node *a, t_stack_node *b);

// push_swap
void					move_nodes(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);

// set
void					set_current_position(t_stack_node *stack);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);

//*** Stack creation ***
void					stack_init(t_stack_node **a, char **argv,
							int flag_argc_2);
void					init_nodes(t_stack_node *a, t_stack_node *b);

//*** linked list utils ***
t_stack_node			*return_cheapest(t_stack_node *stack);
int						stack_sorted(t_stack_node *stack);
int						stack_size(t_stack_node *stack);
void					finish_rotation(t_stack_node **s, t_stack_node *n,
							char c);

int						count_numbers(char **argv);

//*** Algorithms ***
void					sort_stack(t_stack_node **a, t_stack_node **b,
							int size);
void					tiny_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void					sort_large_stack(t_stack_node **a, t_stack_node **b);

//*** Commands ***
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

void					reverse_rotate(t_stack_node **stack);
void					reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

#endif

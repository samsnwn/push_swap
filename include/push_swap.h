/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:22:41 by samcasti          #+#    #+#             */
/*   Updated: 2024/10/22 16:00:38 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>

// NODE STRUCT
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// STACK STRUCT
typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

// MAIN FUNCTIONS
void				push_swap(int *arr, size_t arr_len);

// ARRAY UTILS
void					free_array(char **arr);
size_t				arr_length(char **arr);


// INPUT PARSING AND CHECKS
int					*create_int_arr(char **str_arr, size_t arr_len);
int 				*parse_input(int argc, char **argv);
int					str_check_atoi(char *str);
int					array_checks(int *arr, size_t arr_len);

// ERROR HANDLING
int					error_handler(char *err_str);

// OPERATIONS
void				sa(t_stack *a);
void				sb(t_stack *a);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *a);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *a);
void				rrr(t_stack *a, t_stack *b);

// LIST UTILS
void 				lstadd_back(t_node **head, t_node *new);
void 				free_list(t_node **head);

void test_stacks(t_stack *a, t_stack *b);

#endif

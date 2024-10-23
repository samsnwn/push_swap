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

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

void				push_swap(int *arr, size_t arr_len);

size_t				arr_length(char **arr);
void				free_array(char **arr);
int					array_checks(int *arr, size_t arr_len);
int					str_atoi(char *str);

int					error_handler(char *err_str);

void				sa(t_stack *a);
void				sb(t_stack *a);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a);
void				pb(t_stack *a);
void				ra(t_stack *a);
void				rb(t_stack *a);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *a);
void				rrr(t_stack *a, t_stack *b);

#endif

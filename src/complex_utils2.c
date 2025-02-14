/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:59:36 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 17:58:48 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->is_optimal)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	execute_optimal_rotations(t_stack_node **a, t_stack_node **b,
		t_stack_node *node)
{
	while (*a != node->target && *b != node)
	{
		if (node->upper_half && node->target->upper_half)
			rr(a, b);
		else if (!node->upper_half && !node->target->upper_half)
			rrr(a, b);
		else
			break ;
	}
	update_positions(*a);
	update_positions(*b);
}

void	complete_rotation(t_stack_node **stack, t_stack_node *top,
		char stack_id)
{
	while (*stack != top)
	{
		if (stack_id == 'a')
		{
			if (top->upper_half)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top->upper_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	execute_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	node = return_cheapest(*b);
	execute_optimal_rotations(a, b, node);
	complete_rotation(b, node, 'b');
	complete_rotation(a, node->target, 'a');
	pa(a, b);
}

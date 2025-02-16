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

t_stack_node	*find_best_move(t_stack_node *b)
{
	t_stack_node	*best_node;
	int				min_cost;
	
	min_cost = INT_MAX;
	best_node = NULL;
	while (b)
	{
		if (b->cost < min_cost)
		{
			min_cost = b->cost;
			best_node = b;
		}
		b = b->next;
	}
	return (best_node);
}

void	do_rotations(t_stack_node **a, t_stack_node **b, t_stack_node *node)
{
	while (*b != node && *a != node->target)
	{
		if (node->upper_half && node->target->upper_half)
			rr(a, b);
		else if (!node->upper_half && !node->target->upper_half)
			rrr(a, b);
		else
			break;
	}
	while (*b != node)
	{
		if (node->upper_half)
			rb(b);
		else
			rrb(b);
	}
	while (*a != node->target)
	{
		if (node->target->upper_half)
			ra(a);
		else
			rra(a);
	}
}

void	rotate_to_min(t_stack_node **stack)
{
	t_stack_node	*min;
	
	min = find_smallest(*stack);
	if (min->upper_half)
	{
		while (*stack != min)
			ra(stack);
	}
	else
	{
		while (*stack != min)
			rra(stack);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:00:30 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 18:14:52 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_positions(t_stack_node *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (stack == NULL)
		return ;
	mid = stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->upper_half = TRUE;
		else
			stack->upper_half = FALSE;
		stack = stack->next;
		i++;
	}
}

void	find_optimal_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->num > b->num && current->num < best_match)
			{
				best_match = current->num;
				target = current;
			}
			current = current->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	calculate_move_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->pos;
		if (!b->upper_half)
			b->cost = len_b - b->pos;
		if (b->target->upper_half)
			b->cost += b->target->pos;
		else
			b->cost += len_a - b->target->pos;
		b = b->next;
	}
}

void	mark_cheapest_move(t_stack_node *b)
{
	long			min_cost;
	t_stack_node	*cheapest;

	if (b == NULL)
		return ;
	min_cost = LONG_MAX;
	while (b)
	{
		if (b->cost < min_cost)
		{
			min_cost = b->cost;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->is_optimal = TRUE;
}

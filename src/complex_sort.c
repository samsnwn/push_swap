/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:00:30 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/17 16:37:13 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_b(t_stack_node **src, t_stack_node **dst, int count)
{
	while (count-- > 3)
		pb(dst, src);
}

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

void	set_target_nodes(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_val;

	while (b)
	{
		best_val = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->num > b->num && current->num < best_val)
			{
				best_val = current->num;
				target = current;
			}
			current = current->next;
		}
		if (best_val == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	calculate_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = get_target_cost(b, len_a, len_b);
		b = b->next;
	}
}

int	get_target_cost(t_stack_node *node, int len_a, int len_b)
{
	int	total_cost;

	total_cost = node->pos;
	if (!node->upper_half)
		total_cost = len_b - node->pos;
	if (node->target->upper_half)
		total_cost += node->target->pos;
	else
		total_cost += len_a - node->target->pos;
	return (total_cost);
}

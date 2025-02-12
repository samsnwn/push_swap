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
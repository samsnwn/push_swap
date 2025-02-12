#include "../include/push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= centerline)
			stack->upper_half = TRUE;
		else
			stack->upper_half = FALSE;
		stack = stack->next;
		++i;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match_index)
			{
				best_match_index = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->pos;
		if (!(b->upper_half))
			b->cost = len_b - (b->pos);
		if (b->target->upper_half)
			b->cost += b->target->pos;
		else
			b->cost += len_a - (b->target->pos);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long best_match_value;
	t_stack_node *best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->cost < best_match_value)
		{
			best_match_value = b->cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->is_optimal = TRUE;
}
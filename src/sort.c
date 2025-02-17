/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:06:49 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 17:47:47 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b, int size)
{
	if (!stack_sorted(*a))
	{
		if (size == 2)
			sa(a);
		else if (size == 3)
			sort_three(a);
		else
			sort_large_stack(a, b);
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	sort_large_stack(t_stack_node **a, t_stack_node **b)
{
	int		stack_len;
	t_stack_node	*best_move;
	
	stack_len = stack_size(*a);
	push_to_b(a, b, stack_len);
	sort_three(a);
	
	while (*b)
	{
		update_positions(*a);
		update_positions(*b);
		set_target_nodes(*a, *b);
		calculate_costs(*a, *b);
		best_move = find_best_move(*b);
		do_rotations(a, b, best_move);
		pa(a, b);
	}
	rotate_to_min(a);
}

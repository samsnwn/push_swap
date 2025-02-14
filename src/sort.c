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
			tiny_sort(a);
		else
			sort_large_stack(a, b);
	}
}

void	tiny_sort(t_stack_node **a)
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
	t_stack_node		*smallest;
	int					len;

	len = stack_size(*a);
	while (len-- > 3)
		pb(b, a);
	tiny_sort(a);
	while (*b)
	{
		prepare_nodes(*a, *b);
		execute_move(a, b);
	}
	update_positions(*a);
	smallest = find_smallest(*a);
	if (smallest->upper_half)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

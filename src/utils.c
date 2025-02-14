/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:58:51 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 17:59:11 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_numbers(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (TRUE);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	stack_size(t_stack_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

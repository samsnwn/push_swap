/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:15 by samcasti          #+#    #+#             */
/*   Updated: 2024/10/22 15:23:16 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list(t_node **head, int *arr, size_t arr_len)
{
	size_t	i;
	t_node	*new_node;

	i = -1;
	if (!arr || arr_len == 0)
		return ;
	while (++i < arr_len)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->data = arr[i];
		new_node->next = NULL;
		new_node->prev = NULL;
		lstadd_back(head, new_node);
	}
}

void	create_list_b(t_node **head)
{
	size_t	i;
	t_node	*new_node;
	int		arr[5] = {5, 8, 9, 3, 1};
	size_t	arr_len;

	arr_len = 5;
	// int *arr = {0};
	// size_t arr_len = 0;
	i = -1;
	while (++i < arr_len)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->data = arr[i];
		new_node->next = NULL;
		lstadd_back(head, new_node);
	}
}

void	initialize_stack(t_node *head, t_stack *a)
{
	t_node	*current;

	if (!head || !a)
		return ;
	current = head;
	a->top = head;
	while (current && current->next)
		current = current->next;
	a->bottom = current;
}

void	push_swap(int *arr, size_t arr_len)
{
	t_node *head = NULL;
	t_node *head_b = NULL;
	t_stack *a;
	t_stack *b;

	create_list(&head, arr, arr_len);
	create_list_b(&head_b);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return ;
	initialize_stack(head, a);
	initialize_stack(head_b, b);

	test_stacks(a, b);

	// ft_sort(a);

}
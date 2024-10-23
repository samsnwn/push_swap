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
	t_node	*current;

	current = NULL;
	i = -1;
	while (++i < arr_len)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->data = arr[i];
		new_node->next = NULL;
		if (*head == NULL)
		{
			*head = new_node;
			new_node->prev = NULL;
		}
		else
		{
			current = *head;
			while (current->next)
				current = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}

void	initialize_stack(t_node *head, t_stack *a)
{
	t_node	*current;

	current = head;
	a->top = head;
	while (current && current->next)
		current = current->next;
	a->bottom = current;
}

void	push_swap(int *arr, size_t arr_len)
{
	t_node *head = NULL;
	t_stack *a;
	// t_stack *b;

	create_list(&head, arr, arr_len);
	ft_printf("Elements from linked list:\n");
	t_node *current = head;
	while (current != NULL)
	{
		ft_printf("t_node->data: %d\n", current->data);
		current = current->next;
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return ;
	initialize_stack(head, a);
	ft_printf("Elements from stack A:\n");
	ft_printf("a->top: %d\na->bottom: %d\n", a->top->data, a->bottom->data);
}
#include "../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || !b || !b->top)
		return ;
	temp = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	temp->next = a->top;
	temp->prev = NULL;
	a->top = temp;
	if (a->top->next)
		a->top->next->prev = a->top;
	else
		a->bottom = a->top;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node *temp;

	if (!b || !a || !a->top)
		return ;
	temp = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	temp->next = b->top;
	temp->prev = NULL;
	b->top = temp;
	if (!b->bottom)
		b->bottom = b->top;
	else
		b->top->next->prev = b->top;
}
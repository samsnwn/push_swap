#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	if (a->bottom == NULL)
	{
		a->bottom = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->prev = a->bottom;
		temp->next = NULL;
		a->bottom->next = temp;
		a->bottom = temp;
	}
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (!b || !b->top || !b->top->next)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;

	if (b->bottom == NULL)
	{
		b->bottom = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->prev = b->bottom;
		temp->next = NULL;
		b->bottom->next = temp;
		b->bottom = temp;
	}
}

void rr(t_stack *a, t_stack *b)
{
  if (!a || !b)
    return ;
  ra(a);
  rb(b);
}
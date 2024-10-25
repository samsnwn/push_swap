#include "../include/push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->top->next || !a->top)
		return ;
	temp = a->bottom;
	if (temp->prev)
		a->bottom = temp->prev;
	else
		return ;
	a->bottom->next = NULL;
	temp->next = a->top;
	temp->prev = NULL;
	a->top = temp;
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	if (!b || !b->top->next || !b->top)
		return ;
	temp = b->bottom;
	if (temp->prev)
		b->bottom = temp->prev;
	else
		return ;
	b->bottom->next = NULL;
	temp->next = b->top;
	temp->prev = NULL;
	b->top = temp;
}

void rrr(t_stack *a, t_stack *b)
{
  if (!a || !b)
    return ;
  rra(a);
  rrb(b);
}
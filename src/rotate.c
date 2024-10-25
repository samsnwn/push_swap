#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top; // copy first node into temp
	a->top = a->top->next; // Assign second node to top
	a->top->prev = NULL;   // make new tops prev NULL
	// If the stack was empty, set bottom to temp
	if (a->bottom == NULL)
	{
		a->bottom = temp;
		temp->next = NULL; // Set next of temp to NULL
		temp->prev = NULL; // Set prev of temp to NULL
	}
	else
	{
		// Link temp to the current bottom
		temp->prev = a->bottom;
		temp->next = NULL;      // Set next of temp to NULL
		a->bottom->next = temp; // Link the current bottom to temp
		a->bottom = temp;       // Update bottom to temp
	}
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (!b || !b->top || !b->top->next)
		return ;
	temp = b->top; // copy first node into temp
	b->top = b->top->next; // Assign second node to top
	b->top->prev = NULL;   // make new tops prev NULL
	// If the stack was empty, set bottom to temp
	if (b->bottom == NULL)
	{
		b->bottom = temp;
		temp->next = NULL; // Set next of temp to NULL
		temp->prev = NULL; // Set prev of temp to NULL
	}
	else
	{
		// Link temp to the current bottom
		temp->prev = b->bottom;
		temp->next = NULL;      // Set next of temp to NULL
		b->bottom->next = temp; // Link the current bottom to temp
		b->bottom = temp;       // Update bottom to temp
	}
}

void rr(t_stack *a, t_stack *b)
{
  if (!a || !b)
    return ;
  ra(a);
  rb(b);
}
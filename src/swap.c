#include "../include/push_swap.h"

void sa(t_stack *a)
{
  t_node *temp;

  if (!a || !a->top || !a->top->next)
    return ;
  temp = a->top;               // Store the first node
  a->top = a->top->next;       // Move the top to the second node
  a->top->prev = NULL;         // Update the prev pointer of the new top
  temp->next = a->top->next;   // Link the first node to the third node
  a->top->next = temp;         // Link the second node to the first node
  temp->prev = a->top;         // Update the prev pointer of the original top
  if (temp->next)              // If there is a third node, update its prev pointer
    temp->next->prev = temp;   // Link the third node's prev to the original top
}

void sb(t_stack *b)
{
  t_node *temp;

  if (!b || !b->top || !b->top->next)
    return ;
  temp = b->top;
  b->top = b->top->next;
  b->top->prev = NULL;
  temp->next = b->top->next;
  b->top->next = temp;
  temp->prev = b->top;
  if (temp->next)
    temp->next->prev = temp;
}

void ss(t_stack *a, t_stack *b)
{
  if (!a || !b)
    return ;
  sa(a);
  sb(b);
}

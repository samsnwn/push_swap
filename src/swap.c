#include "../include/push_swap.h"

void sa(t_stack *a)
{
  t_node *temp;

  if (!a || !a->top || !a->top->next)
    return ;
  temp = a->top;
  a->top = a->top->next;
  a->top->prev = NULL;
  temp->next = a->top->next;
  a->top->next = temp;
  temp->prev = a->top;
  if (temp->next)
    temp->next->prev = temp;
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

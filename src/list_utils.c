#include "../include/push_swap.h"

void lstadd_back(t_node **head, t_node *new)
{
  t_node *current;

  if (new == NULL)
    return ;
  if (*head == NULL)
  {
    *head = new;
    new->prev = NULL;
    new->next = NULL;
  }
  else
  {
    current = *head;
    while (current->next)
      current = current->next;
    current->next = new;
    new->prev = current;
    new->next = NULL;
  }
}

void free_list(t_node **head)
{
  t_node *temp;
  t_node *next_node;

  temp = *head;
  while (temp)
  {
    next_node = temp->next;
    free(temp);
    temp = next_node;
  }
  *head = NULL;
}

size_t stack_size(t_stack *stack)
{
  t_node *current;
  size_t count;

  count = 1;
  current = stack->top;
  while (current->next)
  {
    count++;
   current = current->next; 
  }
  return count;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}


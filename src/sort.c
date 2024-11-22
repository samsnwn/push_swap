#include "../include/push_swap.h"

void	bubble_sort(t_stack *stack)
{
	t_node	*current;
	int		count;
	int		swapped;
	int		size;

	count = -1;
	size = stack_size(stack);
	swapped = 0;
	while (!swapped)
	{
		swapped = 1;
		current = stack->top;
		// Only iterate until the second-to-last node
		while (++count < size - 1 && current->next)
		{
			if (current->data > current->next->data)
			{
				ft_printf("Swapped: %d and %d\n", current->data, current->next->data);
				sa(stack);
				count++;
				swapped = 0;
			}
			current = current->next;
		}
	}
	ft_printf("%d\n", count);
}

void	ft_sort(t_stack *a)
{
	if (is_sorted(a))
		return ;
	// free_everything_finish();
	else
	{
		if (stack_size(a) == 2)
			sa(a);
		else if (stack_size(a) == 3)
			// sort 3 node function
			bubble_sort(a);
		// else
		// 	// complex sort
	}
}
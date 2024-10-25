#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node *current = stack->top;
	int i = 1;
	while (current)
	{
		ft_printf("%d - > %d\n", i, current->data);
		current = current->next;
		i++;
	}
}

void test_stacks(t_stack *a, t_stack *b)
{
	// ORIGINAL STACKS
	ft_printf("Original Order from stack A:\n");
	print_stack(a);
	ft_printf("Original Order from stack B:\n");
	print_stack(b);

// // SWAP A
// 	ft_printf("After swaped elements from A:\n");
// 	sa(a);
// 	print_stack(a);

// // SWAP B
// 	ft_printf("After swaped elements from B:\n");
// 	sb(b);
// 	print_stack(b);

// // SWAP BOTH
	// ft_printf("After swaped BOTH stacks:\n");
	// ss(a, b);
  // ft_printf("STACK A:\n");
  // print_stack(a);
  // ft_printf("STACK B:\n");
	// print_stack(b);

// // PUSH A
// 	ft_printf("Pushed top of b into a:\n");
// 	pa(a, b);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);

// PUSH B
	// ft_printf("Pushed top of a into b:\n");
	// pb(a, b);
	// ft_printf("STACK A:\n");
	// print_stack(a);
	// ft_printf("STACK B:\n");
	// print_stack(b);

// // ROTATE A
//   ft_printf("Rotate top of a to the bottom:\n");
// 	ra(a);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);

// // ROTATE B
//   ft_printf("Rotate top of B to the bottom:\n");
// 	rb(b);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);

// // ROTATE BOTH
//   ft_printf("Rotate BOTH:\n");
//   rr(a, b);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);
}
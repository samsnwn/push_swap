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
	ft_printf("----------------------------\n");
	ft_printf("Original Order from stack A:\n");
	print_stack(a);
	ft_printf("Original Order from stack B:\n");
	print_stack(b);
	ft_printf("----------------------------\n");
	ft_printf("\n");

// // SWAP A
// 	ft_printf("After swaped elements from A:\n");
// 	sa(a);
// 	print_stack(a);
// ft_printf("\n");


// // SWAP B
// 	ft_printf("After swaped elements from B:\n");
// 	sb(b);
// 	print_stack(b);
// ft_printf("\n");


// // SWAP BOTH
	// ft_printf("After swaped BOTH stacks:\n");
	// ss(a, b);
  // ft_printf("STACK A:\n");
  // print_stack(a);
  // ft_printf("STACK B:\n");
	// print_stack(b);
	// ft_printf("\n");

// // PUSH A
// 	ft_printf("Pushed top of b into a:\n");
// 	pa(a, b);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);
// ft_printf("\n");

// PUSH B
	// ft_printf("Pushed top of a into b:\n");
	// pb(a, b);
	// ft_printf("STACK A:\n");
	// print_stack(a);
	// ft_printf("STACK B:\n");
	// print_stack(b);
	// ft_printf("\n");

// // ROTATE A
//   ft_printf("Rotate top of a to the bottom:\n");
// 	ra(a);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// ft_printf("\n");

// ROTATE B
  ft_printf("Rotate top of B to the bottom:\n");
	rb(b);
	ft_printf("STACK B:\n");
	print_stack(b);
ft_printf("\n");

// // ROTATE BOTH
//   ft_printf("Rotate BOTH:\n");
//   rr(a, b);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);
// ft_printf("\n");

// // REVERSE ROTATE A
//   ft_printf("Reverse Rotate A:\n");
//   rra(a);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// ft_printf("\n");

// // REVERSE ROTATE B
//   ft_printf("Reverse Rotate B:\n");
//   rrb(b);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);
// ft_printf("\n");

// // REVERSE ROTATE BOTH
//   ft_printf("Reverse Rotate BOTH:\n");
//   rrr(a, b);
// 	ft_printf("STACK A:\n");
// 	print_stack(a);
// 	ft_printf("STACK B:\n");
// 	print_stack(b);
// 	ft_printf("\n");
}
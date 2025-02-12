#include "../include/push_swap.h"

t_stack_node	*create_stack_from_array(int *numbers, int size)
{
	t_stack_node	*stack;
	int				i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		append_node(&stack, numbers[i]);
		i++;
	}
	return (stack);
}

void	stack_init(t_stack_node **a, char **argv, int flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_args(argv);
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
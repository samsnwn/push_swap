#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	int *numbers;
	int size;
	int error;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	error = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		size = count_numbers(argv);
		numbers = convert_to_int_array(argv, size, &error);
	}
	else
	{
		size = count_numbers(argv + 1);
		numbers = convert_to_int_array(argv + 1, size, &error);
	}
	if (error || !numbers || check_duplicates(numbers, size))
		handle_input_error(numbers, argv, argc == 2);
	a = create_stack_from_array(numbers, size);
	b = NULL;
	free(numbers);
	if (argc == 2)
		free_matrix(argv);
	if (!stack_sorted(a))
	{
		if (size == 2)
			sa(&a);
		else if (size == 3)
			tiny_sort(&a);
		else
			sort_large_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
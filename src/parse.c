#include "../include/push_swap.h"

int count_numbers(char **argv)
{
	int i;
	
	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int *convert_to_int_array(char **argv, int size, int *error)
{
	int *numbers;
	int i;
	long num;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (error_syntax(argv[i]))
		{
			free(numbers);
			*error = 1;
			return (NULL);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(numbers);
			*error = 1;
			return (NULL);
		}
		numbers[i] = (int)num;
		i++;
	}
	return (numbers);
}

int check_duplicates(int *numbers, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack_node *create_stack_from_array(int *numbers, int size)
{
	t_stack_node *stack;
	int i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		append_node(&stack, numbers[i]);
		i++;
	}
	return (stack);
}
#include "../include/push_swap.h"

int	*parse_args(int argc, char **argv, int *size, int *is_split)
{
	int	*numbers;
	int	error;

	error = 0;
	*is_split = 0;
	if (argc == 2)
	{
		*is_split = 1;
		numbers = handle_single_arg(argv, size, &error);
	}
	else
		numbers = handle_multiple_args(argv, size, &error);
	if (error || !numbers || check_duplicates(numbers, *size))
		handle_input_error(numbers, argv, *is_split);
	return (numbers);
}

int	*handle_single_arg(char **argv, int *size, int *error)
{
	int		*numbers;
	char	**split_args;

	split_args = ft_split(argv[1], ' ');
	if (!split_args)
		return (NULL);
	*size = count_numbers(split_args);
	numbers = convert_to_int_array(split_args, *size, error);
	free_args(split_args);
	return (numbers);
}

int	*handle_multiple_args(char **argv, int *size, int *error)
{
	*size = count_numbers(argv + 1);
	return (convert_to_int_array(argv + 1, *size, error));
}

int	*convert_to_int_array(char **argv, int size, int *error)
{
	int		*numbers;
	int		i;
	long	num;

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

int	check_duplicates(int *numbers, int size)
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
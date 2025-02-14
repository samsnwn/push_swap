/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:03:04 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/14 14:52:24 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*handle_split_args(char **split_args, int *size, int *error)
{
	int	*numbers;

	if (!split_args)
		return (NULL);
	*size = count_numbers(split_args);
	numbers = convert_to_int_array(split_args, *size, error);
	if (*error || !numbers || check_duplicates(numbers, *size))
	{
		if (numbers)
			free(numbers);
		free_args(split_args);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	free_args(split_args);
	return (numbers);
}

static int	*handle_direct_args(char **argv, int *size, int *error)
{
	int	*numbers;

	*size = count_numbers(argv + 1);
	numbers = convert_to_int_array(argv + 1, *size, error);
	if (*error || !numbers || check_duplicates(numbers, *size))
	{
		if (numbers)
			free(numbers);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (numbers);
}

int	*parse_args(int argc, char **argv, int *size, int *is_split)
{
	int		*numbers;
	char	**split_args;

	*is_split = 0;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		numbers = handle_split_args(split_args, size, is_split);
	}
	else
		numbers = handle_direct_args(argv, size, is_split);
	return (numbers);
}

int	*convert_to_int_array(char **argv, int size, int *error)
{
	int		*numbers;
	int		i;
	long	num;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (error_syntax(argv[i]))
		{
			number_free(numbers, error);
			return (NULL);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			number_free(numbers, error);
			return (NULL);
		}
		numbers[i] = (int)num;
	}
	return (numbers);
}

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

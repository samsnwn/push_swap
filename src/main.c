/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:03 by samcasti          #+#    #+#             */
/*   Updated: 2024/10/22 16:27:55 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	// t_stack *a = NULL;
	// t_stack *b = NULL;
	int		*int_arr;
	char	**str_arr;
	size_t	arr_len;

	arr_len = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (error_handler("Incorrect Number of arguments"));
	if (argc == 2 && argv[1][0])
	{
		str_arr = ft_split(argv[1], ' ');
		arr_len = arr_length(str_arr);
		int_arr = create_int_arr(str_arr, arr_len);
		free_array(str_arr);
	}
	if (argc > 2)
	{
		arr_len = argc - 1;
		int_arr = create_int_arr(argv + 1, arr_len);
	}
	if (!int_arr)
		return (error_handler("Invalid argument format"));
	// int_arr = parse_input(argc, argv);
	// arr_len = int_arr_length(int_arr);
	if (array_checks(int_arr, arr_len) == 1)
	{
		free(int_arr);
		return (error_handler("Numbers must be unique"));
	}
	push_swap(int_arr, arr_len);
	// size_t		i = 0;
	// while (i < arr_len)
	// {
	// 	ft_printf("%d\n", int_arr[i]);
	// 	i++;
	// }
	free(int_arr);
	return (EXIT_SUCCESS);
}

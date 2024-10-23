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

int	str_atoi(char *str)
{
	int	j;

	if (ft_isdigit(str[0]) || (str[0] == '-' && ft_isdigit(str[1])))
	{
		if (str[0] == '-')
			j = 1;
		else
			j = 0;
		while (str[j])
		{
			if (!ft_isdigit(str[j]))
				return (0);
			j++;
		}
		return (ft_atoi(str));
	}
	return (0);
}

int	*create_int_arr(char **str_arr, int arr_len)
{
	int	*int_arr;
	int	i;

	int_arr = malloc(arr_len * sizeof(int));
	if (!int_arr)
		return (NULL);
	i = -1;
	while (++i < arr_len)
	{
		int_arr[i] = str_atoi(str_arr[i]);
		if (int_arr[i] == 0 && str_arr[i][0] != '0')
    {
      free(int_arr);
			return (0);
    }
	}
	return (int_arr);
}

int	main(int argc, char **argv)
{
	char	**str_arr;
	int		*int_arr;
	int		arr_len;

	arr_len = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return error_handler("Incorrect Number of arguments");
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
		return error_handler("Invalid argument format");
  if (array_checks(int_arr, arr_len) == 1)
  {
    free(int_arr);
		return error_handler("Numbers must be unique");
  }
	int		i = 0;
	while (i < arr_len)
	{
		ft_printf("%d\n", int_arr[i]);
		i++;
	}

  free(int_arr);
	return (EXIT_SUCCESS);
}

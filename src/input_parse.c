#include "../include/push_swap.h"

int	str_check_atoi(char *str)
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
		return (atol(str));
	}
	return (0);
}

int	*create_int_arr(char **str_arr, size_t arr_len)
{
	int		*int_arr;
	size_t	i;

	int_arr = malloc(arr_len * sizeof(int));
	if (!int_arr || !str_arr || arr_len == 0)
		return (0);
	i = -1;
	while (++i < arr_len)
	{
		int_arr[i] = (int)str_check_atoi(str_arr[i]);
		if (int_arr[i] == 0 && str_arr[i][0] != '0')
		{
			free(int_arr);
			return (0);
		}
	}
	return (int_arr);
}

int *parse_input(int argc, char **argv)
{
	int		*int_arr = NULL;
  char **str_arr;
	size_t	arr_len;

  if (argc == 2 && argv[1][0])
  {
    str_arr = ft_split(argv[1], ' ');
    arr_len = arr_length(str_arr);
    int_arr = create_int_arr(str_arr, arr_len);
		free_array(str_arr);
  }
  else if (argc > 2)
  {
    arr_len = argc - 1;
		int_arr = create_int_arr(argv + 1, arr_len);
  }
  // if (!int_arr)
	// 	return (error_handler("Invalid argument format"));
  return (int_arr);
}
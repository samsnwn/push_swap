#include "../include/push_swap.h"

size_t arr_length(char **arr)
{
    size_t count;

    count = 0;
    while (arr[count])
        count++;
    return (count);
}

void    free_array(char **arr)
{
    int i;
    int arr_len;

    i = 0;
    arr_len = arr_length(arr);
    while (i < arr_len)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

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
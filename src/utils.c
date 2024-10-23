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
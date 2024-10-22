#include "../include/push_swap.h"

size_t arr_length(char **arr)
{
    int i;
    size_t count;

    i = 0;
    count = 0;
    while (arr[i])
    {
        count++;
        i++;
    }
    return (count);
}
#include "../include/push_swap.h"

int has_repeated_numbers(int *arr, size_t arr_len)
{
  size_t i;
  size_t j;

  i = 0;
  while (i < arr_len)
  {
    j = i + 1;
    while (j < arr_len)
    {
      if (arr[i] == arr[j])
        return 1;
      j++;
    }
    i++;
  }
  return 0;
}

// Not working properly
int is_long(int *arr, size_t arr_len)
{
  size_t i;

  i = 0;
  while (i < arr_len)
  {
    if (arr[i] > INT_MAX || arr[i] < INT_MIN)
      return 1;
    i++;
  }
  return 0;
}

int array_checks(int *arr, size_t arr_len)
{
  if (!has_repeated_numbers(arr, arr_len) && !is_long(arr, arr_len))
    return 0;
  else
    return 1;
}


#include "../include/push_swap.h"

int has_repeated_numbers(int *arr, int arr_len)
{
  int i;
  int j;

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

int array_checks(int *arr, int arr_len)
{
  // check for repeated numbers,
  if (!has_repeated_numbers(arr, arr_len))
    return 0;
  else
    return 1;
}


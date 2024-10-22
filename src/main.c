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

int main(int argc, char **argv)
{
  char  **str_arr;
  // int   *int_arr = NULL;
  int i = 0;
  size_t arr_len = 0;

  if (argc == 1 || (argc == 2 && !argv[1][0]))
    return (EXIT_FAILURE);
  // If argc = 2 => ./push_swap "1 2 4 6 7"
    // split argv[1] into separate strings, transform them into numbers and create nodes

  if (argc == 2 && argv[1][0])
  {
    str_arr = ft_split(argv[1], ' ');
    arr_len = arr_length(str_arr);
    while (arr_len > 0)
    {
      ft_printf("%s\n", str_arr[i]);
      // int_arr[i] = ft_atoi(str_arr[i]);
      i++;
      arr_len--;
    }
    // i = 0;
    // while (int_arr[i])
    // {
    //   ft_printf("%d\n", int_arr[i]);
    //   i++;
    // }
  }


  // If argc > 2 => ./push_swap 1 4 6 8 3
    // each arg will be a new node 
  // if (argc > 2)
  // {

  // }
  return (EXIT_SUCCESS);
}

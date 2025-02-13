/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:01:41 by samcasti          #+#    #+#             */
/*   Updated: 2025/02/13 14:14:45 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node		*a;
	t_stack_node		*b;
	int					*numbers;
	int					size;
	int					is_split;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	numbers = parse_args(argc, argv, &size, &is_split);
	a = create_stack_from_array(numbers, size);
	b = NULL;
	free(numbers);
	sort_stack(&a, &b, size);
	free_stack(&a);
	return (0);
}

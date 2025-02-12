#include "../include/push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (TRUE);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->num > highest)
		{
			highest = stack->num;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}

static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_size(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->num = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->num < smallest)
		{
			smallest = stack->num;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->is_optimal)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_size(t_stack_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

void	stack_init(t_stack_node **a, char **argv, int flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_size(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= centerline)
			stack->upper_half = TRUE;
		else
			stack->upper_half = FALSE;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match_index)
			{
				best_match_index = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->pos;
		if (!(b->upper_half))
			b->cost = len_b - (b->pos);
		if (b->target->upper_half)
			b->cost += b->target->pos;
		else
			b->cost += len_a - (b->target->pos);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->cost < best_match_value)
		{
			best_match_value = b->cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->is_optimal = TRUE;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->upper_half)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->upper_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->upper_half && cheapest_node->target->upper_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->upper_half)
		&& !(cheapest_node->target->upper_half))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_size(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->upper_half)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv, int flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->num == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	update_positions(t_stack_node *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (stack == NULL)
		return;
	mid = stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->upper_half = TRUE;
		else
			stack->upper_half = FALSE;
		stack = stack->next;
		i++;
	}
}

static void	calculate_move_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->pos;
		if (!b->upper_half)
			b->cost = len_b - b->pos;
		if (b->target->upper_half)
			b->cost += b->target->pos;
		else
			b->cost += len_a - b->target->pos;
		b = b->next;
	}
}

static void	find_optimal_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->num > b->num && current->num < best_match)
			{
				best_match = current->num;
				target = current;
			}
			current = current->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	mark_cheapest_move(t_stack_node *b)
{
	long			min_cost;
	t_stack_node	*cheapest;

	if (b == NULL)
		return ;
	min_cost = LONG_MAX;
	while (b)
	{
		if (b->cost < min_cost)
		{
			min_cost = b->cost;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->is_optimal = TRUE;
}

static void	prepare_nodes(t_stack_node *a, t_stack_node *b)
{
	update_positions(a);
	update_positions(b);
	find_optimal_target(a, b);
	calculate_move_costs(a, b);
	mark_cheapest_move(b);
}

static void	execute_optimal_rotations(t_stack_node **a, t_stack_node **b,
		t_stack_node *node)
{
	while (*a != node->target && *b != node)
	{
		if (node->upper_half && node->target->upper_half)
			rr(a, b);
		else if (!node->upper_half && !node->target->upper_half)
			rrr(a, b);
		else
			break ;
	}
	update_positions(*a);
	update_positions(*b);
}

static void	complete_rotation(t_stack_node **stack, t_stack_node *top,
		char stack_id)
{
	while (*stack != top)
	{
		if (stack_id == 'a')
		{
			if (top->upper_half)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top->upper_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	execute_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	node = return_cheapest(*b);
	execute_optimal_rotations(a, b, node);
	complete_rotation(b, node, 'b');
	complete_rotation(a, node->target, 'a');
	pa(a, b);
}

static void	sort_large_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len;

	len = stack_size(*a);
	while (len-- > 3)
		pb(b, a);
	tiny_sort(a);
	while (*b)
	{
		prepare_nodes(*a, *b);
		execute_move(a, b);
	}
	update_positions(*a);
	smallest = find_smallest(*a);
	if (smallest->upper_half)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

// New helper functions for input processing
static int count_numbers(char **argv)
{
	int i;
	
	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static int *convert_to_int_array(char **argv, int size, int *error)
{
	int *numbers;
	int i;
	long num;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (error_syntax(argv[i]))
		{
			free(numbers);
			*error = 1;
			return (NULL);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(numbers);
			*error = 1;
			return (NULL);
		}
		numbers[i] = (int)num;
		i++;
	}
	return (numbers);
}

static int check_duplicates(int *numbers, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_stack_node *create_stack_from_array(int *numbers, int size)
{
	t_stack_node *stack;
	int i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		append_node(&stack, numbers[i]);
		i++;
	}
	return (stack);
}

static void handle_input_error(int *numbers, char **argv, int is_split)
{
	if (numbers)
		free(numbers);
	if (is_split)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	int *numbers;
	int size;
	int error;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	error = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		size = count_numbers(argv);
		numbers = convert_to_int_array(argv, size, &error);
	}
	else
	{
		size = count_numbers(argv + 1);
		numbers = convert_to_int_array(argv + 1, size, &error);
	}
	if (error || !numbers || check_duplicates(numbers, size))
		handle_input_error(numbers, argv, argc == 2);
	a = create_stack_from_array(numbers, size);
	b = NULL;
	free(numbers);
	if (argc == 2)
		free_matrix(argv);
	if (!stack_sorted(a))
	{
		if (size == 2)
			sa(&a);
		else if (size == 3)
			tiny_sort(&a);
		else
			sort_large_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
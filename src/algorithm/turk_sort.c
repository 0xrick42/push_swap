#include "../../includes/push_swap.h"

static int	get_position(t_stack *stack, int num)
{
	t_stack	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current->next != stack)
	{
		if (current->value == num)
			return (pos);
		pos++;
		current = current->next;
	}
	if (current->value == num)
		return (pos);
	return (-1);
}

static int	count_moves(t_stack *a, t_stack *b, int num)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = get_position(a, num);
	pos_b = get_position(b, num);
	size_a = stack_size(a);
	size_b = stack_size(b);
	if (pos_a > size_a / 2)
		pos_a = size_a - pos_a;
	if (pos_b > size_b / 2)
		pos_b = size_b - pos_b;
	return (pos_a + pos_b);
}

int	find_best_move(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		best_num;
	int		best_moves;
	int		moves;

	current = a;
	best_num = current->value;
	best_moves = count_moves(a, b, current->value);
	while (current->next != a)
	{
		current = current->next;
		moves = count_moves(a, b, current->value);
		if (moves < best_moves)
		{
			best_moves = moves;
			best_num = current->value;
		}
	}
	return (best_num);
}

static void	move_number(t_stack **a, t_stack **b, int num)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = get_position(*a, num);
	size_a = stack_size(*a);
	while ((*a)->value != num)
	{
		if (pos_a <= size_a / 2)
			ra(a);
		else
			rra(a);
	}
	if (*b)
	{
		pos_b = get_position(*b, find_max(*b));
		size_b = stack_size(*b);
		while ((*b)->value != find_max(*b))
		{
			if (pos_b <= size_b / 2)
				rb(b);
			else
				rrb(b);
		}
	}
	pb(a, b);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
	while (!is_sorted(*a))
		ra(a);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
		sort_small(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
		while (stack_size(*a) > 3)
		{
			move_number(a, b, find_best_move(*a, *b));
		}
		sort_three(a);
		push_back_to_a(a, b);
	}
}

#include "../../includes/push_swap.h"

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	return (30);
}

bool	find_in_range(t_stack *stack, int min, int max)
{
	t_stack	*current;

	if (!stack)
		return (false);
	current = stack;
	while (current->next != stack)
	{
		if (current->value >= min && current->value <= max)
			return (true);
		current = current->next;
	}
	if (current->value >= min && current->value <= max)
		return (true);
	return (false);
}

static void	push_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	chunk;

	chunk = get_chunk_size(stack_size(*a));
	min = find_min(*a);
	max = min + chunk;
	while (*a)
	{
		if ((*a)->value >= min && (*a)->value <= max)
		{
			pb(a, b);
			if ((*b)->value < min + chunk / 2)
				rb(b);
		}
		else
			ra(a);
		if (!find_in_range(*a, min, max))
		{
			min = max + 1;
			max = min + chunk;
		}
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max(*b);
		pos = get_position(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
			while ((*b)->value != max)
				rb(b);
		else
			while ((*b)->value != max)
				rrb(b);
		pa(a, b);
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
	{
		push_to_b(a, b);
		push_back_to_a(a, b);
	}
}

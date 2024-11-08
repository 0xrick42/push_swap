/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:34:35 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/09 00:00:31 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_position(t_stack *stack, int num, int *size)
{
	t_stack	*current;
	int		pos;

	current = stack;
	pos = 0;
	*size = 1;
	while (current->next != stack)
	{
		if (current->value == num)
			return (pos);
		pos++;
		(*size)++;
		current = current->next;
	}
	if (current->value == num)
		return (pos);
	return (pos);
}

static int	get_cost(t_stack *a, t_stack *b, int num)
{
	t_pos	p;
	int		cost;

	p.a = get_position(a, num, &p.size_a);
	p.b = get_position(b, find_max(b), &p.size_b);
	if (p.a > p.size_a / 2)
		p.a = p.size_a - p.a;
	if (p.b > p.size_b / 2)
		p.b = p.size_b - p.b;
	cost = p.a + p.b;
	return (cost);
}

static int	find_best_move(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		cost;
	int		best_cost;
	int		best_num;

	current = a;
	best_num = current->value;
	best_cost = get_cost(a, b, current->value);
	while (current->next != a)
	{
		current = current->next;
		cost = get_cost(a, b, current->value);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_num = current->value;
		}
	}
	return (best_num);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int		size_a;
	int		pos;
	int		num;

	if (stack_size(*a) <= 5)
		return (sort_small(a, b));
	pb(a, b);
	pb(a, b);
	while (stack_size(*a) > 3)
	{
		num = find_best_move(*a, *b);
		pos = get_position(*a, num, &size_a);
		while ((*a)->value != num)
			if (pos <= size_a / 2)
				ra(a);
		else
			rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

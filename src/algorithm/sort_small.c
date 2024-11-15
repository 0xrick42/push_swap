/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:29:28 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:52:02 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

static int	find_min_position(t_stack *stack, int min)
{
	t_stack	*current;
	int		pos;
	int		i;

	current = stack;
	i = 0;
	pos = 0;
	while (current->next != stack)
	{
		if (current->value == min)
			pos = i;
		i++;
		current = current->next;
	}
	if (current->value == min)
		pos = i;
	return (pos);
}

static void	push_smallest(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	mid;

	min = find_min(*a);
	pos = find_min_position(*a, min);
	mid = (stack_size(*a) + 1) / 2;
	while ((*a)->value != min)
	{
		if (pos <= mid)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3)
		{
			push_smallest(a, b);
			size--;
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}

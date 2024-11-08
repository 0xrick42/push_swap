/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:56:43 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:57:02 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	if (!stack)
		return (0);
	current = stack;
	size = 1;
	while (current->next != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

int	find_min(t_stack *stack)
{
	t_stack	*current;
	int		min;

	if (!stack)
		return (0);
	current = stack;
	min = current->value;
	while (current->next != stack)
	{
		current = current->next;
		if (current->value < min)
			min = current->value;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	if (!stack)
		return (0);
	current = stack;
	max = current->value;
	while (current->next != stack)
	{
		current = current->next;
		if (current->value > max)
			max = current->value;
	}
	return (max);
}

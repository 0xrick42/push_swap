/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:20:33 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/15 16:20:35 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	add_to_stack(t_stack **head, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(head);
		error_exit();
	}
	new->value = value;
	if (!*head)
	{
		*head = new;
		(*head)->next = *head;
		(*head)->prev = *head;
		return ;
	}
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
}

static bool	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	if (!stack)
		return (false);
	current = stack;
	while (current->next != stack)
	{
		check = current->next;
		while (check != stack)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

static void	process_argument(t_stack **head, char *arg)
{
	int		j;
	long	num;
	bool	found_number;

	j = 0;
	found_number = false;
	if (!arg[0])
		error_exit();
	while (arg[j])
	{
		while (arg[j] && (arg[j] == ' ' || (arg[j] >= 9
					&& arg[j] <= 13)))
			j++;
		if (arg[j])
		{
			num = ft_atoi(arg + j);
			if (num > INT_MAX || num < INT_MIN)
				error_exit();
			add_to_stack(head, (int)num);
			found_number = true;
			while (arg[j] && !((arg[j] >= 9 && arg[j] <= 13)
					|| arg[j] == ' '))
				j++;
		}
	}
	if (!found_number)
		error_exit();
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*head;
	int		i;

	if (ac < 2)
		error_exit();
	head = NULL;
	i = 0;
	while (++i < ac)
		process_argument(&head, av[i]);
	if (!head || has_duplicates(head))
		error_exit();
	return (head);
}

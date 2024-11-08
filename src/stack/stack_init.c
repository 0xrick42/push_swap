/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:02:35 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:46:30 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	add_node_to_stack(t_stack **head, t_stack *new)
{
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

bool	check_duplicates(t_stack *stack)
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

static int	validate_number(char *str, t_stack **head)
{
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		free_stack(head);
		error_exit();
	}
	return ((int)num);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*head;
	t_stack	*new;
	int		i;
	int		num;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		num = validate_number(av[i], &head);
		new = new_node(num);
		if (!new)
		{
			free_stack(&head);
			error_exit();
		}
		add_node_to_stack(&head, new);
		i++;
	}
	if (head && check_duplicates(head))
	{
		free_stack(&head);
		error_exit();
	}
	return (head);
}

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

static void	process_number(t_stack **head, char *str, int *i)
{
	long	num;
	t_stack	*new;

	num = ft_atoi(str + *i);
	if (num > INT_MAX || num < INT_MIN)
	{
		free_stack(head);
		error_exit();
	}
	new = new_node((int)num);
	if (!new)
	{
		free_stack(head);
		error_exit();
	}
	add_node_to_stack(head, new);
	while (str[*i] && str[*i] != ' ' && (str[*i] < 9 || str[*i] > 13))
		(*i)++;
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*head;
	int		i;
	int		j;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && (av[i][j] == ' ' || (av[i][j] >= 9
						&& av[i][j] <= 13)))
				j++;
			if (av[i][j])
				process_number(&head, av[i], &j);
		}
		i++;
	}
	if (head && check_duplicates(head))
	{
		free_stack(&head);
		error_exit();
	}
	return (head);
}

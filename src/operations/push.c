/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:20:33 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:56:18 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	remove_from_src(t_stack **src)
{
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
}

static void	add_to_dst(t_stack **dst, t_stack *temp)
{
	if (!*dst)
	{
		*dst = temp;
		(*dst)->next = *dst;
		(*dst)->prev = *dst;
	}
	else
	{
		temp->next = *dst;
		temp->prev = (*dst)->prev;
		(*dst)->prev->next = temp;
		(*dst)->prev = temp;
		*dst = temp;
	}
}

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	remove_from_src(src);
	add_to_dst(dst, temp);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

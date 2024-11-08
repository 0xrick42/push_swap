#include "../../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
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

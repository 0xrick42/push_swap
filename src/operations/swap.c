#include "../../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->next->prev = first;

	second->next = first;
	second->prev = first->prev;

	first->prev->next = second;
	first->prev = second;

	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

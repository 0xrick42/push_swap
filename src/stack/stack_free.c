#include "../../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	if ((*stack)->next == *stack)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	current = (*stack)->next;
	(*stack)->prev->next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

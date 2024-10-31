#include "../includes/push_swap.h"

t_stack *new_node(int value)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizef(t_stack));
    if(!new_node)
        return(NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return(new_node);
}

t_stack *init_stack(int ac, char **av)
{
    t_stack *stack;
    t_stack *current;
    long num;
    int i;

    stack = NULL;
    i = 1;
    while(i < ac)
    {
        num = ft_atoi(av[i])
        if(num > INT_MAX || num < INT_MIN)
            error_exit();
        current = new_node((int)num);
        if(!current)
        {
            free_stack(&stack);
            error_exit();
        }
        if(!stack)
        {
            stack = current;
            stack->next = stack;
            stack->prev = stack;
        }
    }
}

#include "../../includes/push_swap.h"

t_stack *new_node(int value)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if(!new_node)
        return(NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return(new_node);
}

t_stack *init_stack(int ac, char **av)
{
    t_stack *head;
    t_stack *new;
    long num;
    int i;

    head = NULL;
    i = 1;
    while(i < ac)
    {
        num = ft_atoi(av[i]);
        if(num > INT_MAX || num < INT_MIN)
            error_exit();
        new = new_node((int)num);
        if(!new)
        {
            free_stack(&head);
            error_exit();
        }
        if(!head)
        {
            head = new;
            head->next = head;
            head->prev = head;
        }
        else
        {
            new->next = head;
            new->prev = head->prev;
            head->prev->next = new;
            head->prev = new;
        }
        i++;
    }
    if (head && check_duplicates(head))
    {
        free_stack(&head);
        error_exit();
    }
    return(head);
}

bool check_duplicates(t_stack *stack)
{
    t_stack *current;
    t_stack *compare;

    if (!stack)
        return (false);
    current = stack;
    while (current->next != stack)
    {
        compare = current->next;
        while (compare != stack)
        {
            if (current->value == compare->value)
                return (true);
            compare = compare->next;
        }
        current = current->next;
    }
    return (false);
}

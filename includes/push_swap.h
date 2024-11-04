#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/* Structure for our stack nodes */
typedef struct s_stack
{
    int             value;      /* The number stored in this node */
    struct s_stack  *next;      /* Pointer to next node in stack */
    struct s_stack  *prev;      /* Pointer to previous node in stack */
}   t_stack;

/* Stack initialization and memory management */
t_stack *new_node(int value);
t_stack *init_stack(int ac, char **av);
void    free_stack(t_stack **stack);
bool    check_duplicates(t_stack *stack);

/* Operations - Push */
void    pa(t_stack **a, t_stack **b);  /* Push top of b onto a */
void    pb(t_stack **a, t_stack **b);  /* Push top of a onto b */

/* Operations - Swap */
void    sa(t_stack **a);               /* Swap top 2 elements of a */
void    sb(t_stack **b);               /* Swap top 2 elements of b */
void    ss(t_stack **a, t_stack **b);  /* sa and sb together */

/* Operations - Rotate */
void    ra(t_stack **a);               /* Rotate a up by 1 */
void    rb(t_stack **b);               /* Rotate b up by 1 */
void    rr(t_stack **a, t_stack **b);  /* ra and rb together */

/* Operations - Reverse Rotate */
void    rra(t_stack **a);              /* Rotate a down by 1 */
void    rrb(t_stack **b);              /* Rotate b down by 1 */
void    rrr(t_stack **a, t_stack **b); /* rra and rrb together */

/* Stack utility functions */
int     stack_size(t_stack *stack);
bool    is_sorted(t_stack *stack);
int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
void    print_stack(t_stack *stack);  /* Optional: for debugging */

/* Sorting Algorithms */
void    sort_three(t_stack **a);
void    sort_small(t_stack **a, t_stack **b);
void    turk_sort(t_stack **a, t_stack **b);

/* Algorithm Helper Functions */
int     find_best_move(t_stack *a, t_stack *b);
void    do_best_move(t_stack **a, t_stack **b, int num);
void    push_back_to_a(t_stack **a, t_stack **b);

/* Utility Functions */
long    ft_atoi(const char *str);
void    error_exit(void);

#endif

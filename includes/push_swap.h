#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* Stack initialization and validation */
t_stack	*new_node(int value);
t_stack	*init_stack(int ac, char **av);
void	free_stack(t_stack **stack);
bool	check_duplicates(t_stack *stack);

/* Stack operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Stack utilities */
int		stack_size(t_stack *stack);
bool	is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_position(t_stack *stack, int value);

/* Sorting algorithms */
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
void	turk_sort(t_stack **a, t_stack **b);

/* Sort utilities */
int		get_chunk_size(int stack_size);
bool	find_in_range(t_stack *stack, int min, int max);

/* Error handling and utils */
void	error_exit(void);
long	ft_atoi(const char *str);

#endif

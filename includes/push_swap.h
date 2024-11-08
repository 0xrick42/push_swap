/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:42:16 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:44:43 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_pos
{
	int				a;
	int				b;
	int				size_a;
	int				size_b;
}					t_pos;

/* Stack initialization and memory management */
t_stack				*new_node(int value);
t_stack				*init_stack(int ac, char **av);
void				free_stack(t_stack **stack);
bool				check_duplicates(t_stack *stack);

/* Stack utility functions */
int					stack_size(t_stack *stack);
bool				is_sorted(t_stack *stack);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);

/* Operations */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* Sorting algorithms */
void				sort_three(t_stack **stack);
void				sort_small(t_stack **a, t_stack **b);
void				turk_sort(t_stack **a, t_stack **b);

/* Utils */
long				ft_atoi(const char *str);
void				error_exit(void);

#endif
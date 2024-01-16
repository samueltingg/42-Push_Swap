/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:07:01 by sting             #+#    #+#             */
/*   Updated: 2024/01/15 16:57:3 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

// typedef struct s_pv
// {
// 	int				small;
// 	int				large;
// }					t_pv;

// enum				e_loc
// {
// 	TOP_A,
// 	BOT_A,
// 	TOP_B,
// 	BOT_B
// };

// typedef struct s_chunk
// {
// 	enum e_loc		loc;
// 	int				size;
// }					t_chunk;

// typedef struct s_split_destt
// {
// 	t_chunk			min;
// 	t_chunk			mid;
// 	t_chunk			max;
// 	enum e_loc		cur_loc;
// }					t_split_dest;

// UTILS
long				ft_atol(const char *str);
void				delete_stack(t_stack *list);

t_stack				*ft_lstnew_d(int nbr);
void				ft_lstadd_back_d(t_stack **lst, t_stack *new);
int					ft_lstsize_d(t_stack *lst);
t_stack				*ft_lstlast_d(t_stack *lst);

// CHECKING
/**
 * @brief when encounter invalid input, prints "Error\n" & exit program.
 */
void				check_valid_arg(char *str, t_stack *stack);
void				free_n_exit(t_stack *ptr);

/**
 * @brief when encounter duplicates, prints "Error\n" & exit program.
 */
void				check_duplicates(t_stack *head);
int					is_sorted(t_stack *stack);

// INSTRUCTIONS
/**
 * @brief swaps 2 int values without moving nodes
 */
int					swap(t_stack *stack);
void				do_sa(t_stack *stack_a);
void				do_sb(t_stack *stack_b);
void				do_ss(t_stack *stack_a, t_stack *stack_b);

void				push(t_stack **stack_x, t_stack **stack_y);
/**
 * @brief Take 1st element at top of b and put it at top of a
 */
void				do_pa(t_stack **stack_b, t_stack **stack_a);
/**
 * @brief Take 1st element at top of a and put it at top of b
 */
void				do_pb(t_stack **stack_a, t_stack **stack_b);

void				rotate(t_stack **stack);
/**
 * @brief Shift up all elements of stack a by 1.
			The first element becomes the last one.
*/
void				do_ra(t_stack **stack_a);
/**
 * @brief Shift up all elements of stack a by 1.
			The first element becomes the last one.
*/
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate(t_stack **stack);
/**
 * @brief Shift down all elements of stack by 1.
			The last element becomes the first one
*/
void				do_rra(t_stack **stack_a);
/**
 * @brief Shift down all elements of stack by 1.
			The last element becomes the first one
*/
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif

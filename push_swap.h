/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:18:18 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 14:00:32 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// UTILS
long	ft_atol(const char *str);
void	delete_list(t_list *list);

t_list	*ft_lstnew_d(int nbr);
void	ft_lstadd_back_d(t_list **lst, t_list *new);

// CHECKING
void	check_nbr_valid(char *str, t_list *stack);
void	check_duplicates(t_list *head);
int		is_sorted(t_list *stack);

// INSTRUCTIONS
void	swap(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);

void	push(t_list **stack_x, t_list **stack_y);
/**
 * @brief Take 1st element at top of b and put it at top of a
 */
void	pa(t_list **stack_b, t_list **stack_a);
/**
 * @brief Take 1st element at top of a and put it at top of b
 */
void	pb(t_list **stack_a, t_list **stack_b);

void	rotate(t_list **stack);
/**
 * @brief Shift up all elements of stack a by 1.
          The first element becomes the last one.
*/
void	ra(t_list **stack_a);
/**
 * @brief Shift up all elements of stack a by 1.
          The first element becomes the last one.
*/
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	reverse_rotate(t_list **stack);
/**
 * @brief Shift down all elements of stack by 1.
          The last element becomes the first one
*/
void	rra(t_list **stack_a);
/**
 * @brief Shift down all elements of stack by 1.
          The last element becomes the first one
*/
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
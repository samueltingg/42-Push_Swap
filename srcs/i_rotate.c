/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:49:43 by sting             #+#    #+#             */
/*   Updated: 2023/12/13 12:03:52 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
			The first element becomes the last one.
*/
void	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = *stack;
	last_node = ft_lstlast(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

/*
- store first_node
- switch *stack_a to point to first_node->next
- ft_lstlast->next = first node
- first_node->prev = 
- set first_node->next = NULL
*/
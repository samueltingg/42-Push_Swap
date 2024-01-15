/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:49:43 by sting             #+#    #+#             */
/*   Updated: 2024/01/15 16:25:12 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
			The first element becomes the last one.
*/
void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	first_node = *stack;
	last_node = ft_lstlast_d(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if ((*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if ((*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
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

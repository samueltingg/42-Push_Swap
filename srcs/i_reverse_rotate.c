/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:13:22 by sting             #+#    #+#             */
/*   Updated: 2024/01/22 12:33:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!stack || !(*stack))
		return ;
	last_node = ft_lstlast_d(*stack);
	(last_node->prev)->next = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
	last_node->prev = NULL;
}

void	rra(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next == NULL)
		return ;
	if (*stack_b && (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

/*
- store last_node using ft_lstlast
- 2nd_last->next = NULL
- last_node->next = *stack
- first_node->prev = last_node
- switch *stack_a to point to last_node
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:40 by sting             #+#    #+#             */
/*   Updated: 2024/01/15 16:17:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_y, t_stack **stack_x)
{
	t_stack	*first_node_y;

	if (!stack_y && !(*stack_y))
		return ;
	first_node_y = *stack_y;
	*stack_y = first_node_y->next;
	first_node_y->next = *stack_x;
	*stack_x = first_node_y;
	(*stack_x)->prev = NULL;
	if ((*stack_x)->next)
		(*stack_x)->next->prev = *stack_x;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

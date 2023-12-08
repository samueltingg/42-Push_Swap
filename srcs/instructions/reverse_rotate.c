/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:13:22 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 13:57:34 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void reverse_rotate(t_list **stack)
{
    t_list  *last_node;

    last_node = ft_lstlast(*stack);
    (last_node->prev)->next = NULL;
    last_node->next = *stack;
    (*stack)->prev = last_node;
    *stack = last_node;
    last_node->prev = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
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
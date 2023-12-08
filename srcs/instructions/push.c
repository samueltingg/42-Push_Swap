/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:40 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 12:46:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void push(t_list **stack_y, t_list **stack_x)
{
    t_list  *first_node_y;
    
    if (!stack_y && !(*stack_y))
        return ;
    
    first_node_y = *stack_y;
    *stack_y = first_node_y->next;
    
    first_node_y->next = *stack_x;
    *stack_x = first_node_y;
}

void pa(t_list **stack_b, t_list **stack_a)
{
    push(stack_b, stack_a);
    ft_printf("pa\n");
}

void pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pb\n");
}

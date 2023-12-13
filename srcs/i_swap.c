/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:45 by sting             #+#    #+#             */
/*   Updated: 2023/12/13 12:06:52 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int swap(t_list *stack)
{
    int tmp;

    // if (!stack || !(stack->next))
    //     return (-1);
    if (!stack)
        return (-1);
    if (!(stack->next))
        return (-1);
    tmp = (stack)->nbr;
    (stack)->nbr = ((stack)->next)->nbr;
    ((stack)->next)->nbr = tmp;
    return (0);
}

void sa(t_list *stack_a)
{
    if (swap(stack_a) == -1) // remove
        ft_printf("Error(sa): !stack\n");
    else if (swap(stack_a) == -2) // remove
        ft_printf("Error(sa): !stack->next\n");
    else 
    {
        swap(stack_a);
        ft_printf("sa\n");
    }
}

void sb(t_list *stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}
void ss(t_list *stack_a, t_list *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
}
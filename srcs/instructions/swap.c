/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:45 by sting             #+#    #+#             */
/*   Updated: 2023/12/07 13:37:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void swap(t_list *stack)
{
    int tmp;

    tmp = (stack)->nbr;
    (stack)->nbr = ((stack)->next)->nbr;
    ((stack)->next)->nbr = tmp;
}

void sa(t_list *stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
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
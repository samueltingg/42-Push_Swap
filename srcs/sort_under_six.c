/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:37:48 by sting             #+#    #+#             */
/*   Updated: 2023/12/12 12:00:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sort3(t_list **stack)
{
    t_list  *first;
    t_list  *second;
    t_list  *third;

    first = *stack;
    second = (*stack)->next;
    third = ((*stack)->next)->next;

    if (first->nbr > second->nbr && first->nbr > third->nbr)
        ra(stack);
    else if (second->nbr > first->nbr && second->nbr > third->nbr)
        rra(stack);
    if ((*stack)->nbr > (*stack)->next->nbr)
        sa(*stack);
}

int find_smallest(t_list *stack)
{
    int smallest; 

    smallest = stack->nbr;
    stack = stack->next;
    while (stack)
    {
        if (stack->nbr < smallest)
            smallest = stack->nbr;
        stack = stack->next;
    }
    return (smallest);
}

/**
 * @brief returns ptr of node with smallest nbr
*/
t_list  *find_smallest(t_list *stack)
{
    t_list  *smallest; 

    smallest = stack;
    stack = stack->next;
    while (stack)
    {
        if (stack->nbr < smallest->nbr)
            smallest = stack;
        stack = stack->next;
    }
    return (smallest);
}

void    insertion_sort(t_list **stack_a, t_list **stack_b)
{
    int smallest;
    
    while (*stack_a)
    {
        smallest = find_smallest(*stack_a);
        while ((*stack_a)->nbr != smallest)
            ra(stack_a);
        pb(stack_a, stack_b);
    }
    while (*stack_b)
        pa(stack_b, stack_a);
}


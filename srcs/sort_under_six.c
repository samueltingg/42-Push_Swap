/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:37:48 by sting             #+#    #+#             */
/*   Updated: 2023/12/12 08:21:56 by sting            ###   ########.fr       */
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

void    insertion_sort(t_list **stack_a, t_list **stack_b)
{
    int key;
    t_list  *ptr;
    t_list  *current;
    
    current = (*stack_a)->next;
    while (current)
    {
        key = current->nbr;
        ptr = current->prev;
        if (ptr && (ptr->nbr > key))
        {
            while ((*stack_a)->nbr != key) // stop push when nbr is key
                pb(stack_a, stack_b); 
            sa(*stack_a);
            while (*stack_b) // transfer from stack_b until empty
                pa(stack_b, stack_a);
        }
        if (ptr == NULL)
            (*stack_a)->nbr = key;
        else
            ptr->next->nbr = key;
        current = current->next;
    }
}
hello
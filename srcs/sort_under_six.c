/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:37:48 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 14:58:23 by sting            ###   ########.fr       */
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

    // Case: 3 1 2
    if (first->nbr > third->nbr && third->nbr > second->nbr)
        ra(stack);
    
    
}
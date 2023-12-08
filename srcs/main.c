/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 13:57:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_list  *stack_a;
    t_list  *new;
    int nbr_count;

    stack_a = NULL;
    if (argc <= 2)
        return (-1);
    
    // create stack
    i = 1;
    while (argv[i] != NULL) 
    {
        check_nbr_valid(argv[i], stack_a); // ERROR CHECKING
        new = ft_lstnew_d(ft_atoi(argv[i])); // malloc
        ft_lstadd_back_d(&stack_a, new);
        i++;
    }
    check_duplicates(stack_a); // ERROR CHECKING
    if (is_sorted(stack_a))
        exit (-1);

    t_list  *stack_b;

    stack_b = ft_lstnew_d(10);
    ft_lstadd_back_d(&stack_b, ft_lstnew_d(11));
    ft_lstadd_back_d(&stack_b, ft_lstnew_d(9));
    
    // check created stack
    t_list *stack2_a = stack_a;
    while (stack2_a != NULL)
    {
        ft_printf("nbr_a = %d\n", stack2_a->nbr);    
        stack2_a = stack2_a->next;
    }
    ft_printf("\n");
    t_list *stack2_b = stack_b;
    while (stack2_b != NULL)
    {
        ft_printf("nbr_b = %d\n", stack2_b->nbr);    
        stack2_b = stack2_b->next;
    }
    ft_printf("\n");
    

    nbr_count = ft_lstsize(stack_a);
    if (nbr_count == 2)
    {
        if (stack_a->nbr > (stack_a->next)->nbr)
            sa(stack_a);
    }
    // ra(&stack_a);

    // push check
    // pa(&stack_b, &stack_a);
    // pa(&stack_b, &stack_a);
    // pb(&stack_a, &stack_b);

    rrr(&stack_a, &stack_b);
    
    // check final stack
    ft_printf("\n------After sort------\n"); 
    while (stack_a != NULL)
    {
        ft_printf("nbr_a = %d\n", stack_a->nbr);    
        if (stack_a->prev)
            ft_printf("prev = %d\n", stack_a->prev->nbr);    
        else 
            ft_printf("prev = NULL\n");
        stack_a = stack_a->next;
    }
    ft_printf("\n");
    while (stack_b != NULL)
    {
        ft_printf("nbr_b = %d\n", stack_b->nbr);
        if (stack_b->prev)
            ft_printf("prev = %d\n", stack_b->prev->nbr);    
        else 
            ft_printf("prev = NULL\n");
        stack_b = stack_b->next;
    }
}
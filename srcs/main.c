/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2023/12/07 13:30:49 by sting            ###   ########.fr       */
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
        new = ft_lstnew(ft_atoi(argv[i])); // malloc
        ft_lstadd_back(&stack_a, new);
        i++;
    }
    check_duplicates(stack_a); // ERROR CHECKING
    if (is_sorted(stack_a))
        exit (-1);

    // check created stack
    t_list *stack2 = stack_a;
    while (stack2 != NULL)
    {
        ft_printf("nbr = %d\n", stack2->nbr);    
        stack2 = stack2->next;
    }
    ft_printf("\n");
    

    nbr_count = ft_lstsize(stack_a);
    if (nbr_count == 2)
        sa(stack_a);

    
    // check final stack
    ft_printf("\nAfter sort\n"); 
    while (stack_a != NULL)
    {
        ft_printf("nbr = %d\n", stack_a->nbr);    
        stack_a = stack_a->next;
    }
}
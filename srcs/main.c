/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2024/01/09 16:57:30 by sting            ###   ########.fr       */
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
    // create stack
    i = 1;
    while (argv[i] != NULL)
    {
        // printf("argv[i]: %s\n", argv[i]);
        check_valid_arg(argv[i], stack_a); // ERROR CHECKING
        new = ft_lstnew_d(ft_atoi(argv[i])); // malloc
        ft_lstadd_back_d(&stack_a, new);
        i++;
    }
    if (argc <= 2)
        return (-1);
    check_duplicates(stack_a); // ERROR CHECKING
    if (is_sorted(stack_a))
        exit (-1);
    // ---------------------------------------------

    // stack b
    t_list  *stack_b;
    stack_b = NULL;

    // check created stack
    // t_list *stack2_a = stack_a;
    // printf("\nStack Creation\n");
    // while (stack2_a != NULL)
    // {
    //     printf("nbr_a = %d\n", stack2_a->nbr);
    //     stack2_a = stack2_a->next;
    // }
    // printf("\n");
    // t_list *stack2_b = stack_b;
    // while (stack2_b != NULL)
    // {
    //     printf("nbr_b = %d\n", stack2_b->nbr);
    //     stack2_b = stack2_b->next;
    // }
    // printf("\n");

    nbr_count = ft_lstsize(stack_a);
    if (nbr_count == 2)
    {
        if (stack_a->nbr > (stack_a->next)->nbr)
            sa(stack_a);
    }
    else if (nbr_count == 3)
        sort3(&stack_a);
    else if (nbr_count == 4 || nbr_count == 5)
        sort4_or_5(&stack_a, &stack_b, nbr_count);
    else if (nbr_count > 5)
    {
        assign_index(stack_a);
        quick_sort3(&stack_a, &stack_b, TOP_A, nbr_count);
    }

    // CHECK: Assigned Index (working)
    // assign_index(stack_a);
    // t_list *tmp = stack_a;
    // while (tmp)
    // {
    //     printf("%i ->", tmp->nbr);
    //     printf("index: %i\n", tmp->index);
    //     tmp = tmp->next;
    // }

    // CHECK: Partition


    // check final stack
    // printf("\n------After sort------\n");
    // printf("-- Stack A --");
    // while (stack_a != NULL)
    // {
    //     printf("\nnbr_a = %d", stack_a->nbr);
    //     // if (stack_a->prev)
    //     //     printf("    prev = %d", stack_a->prev->nbr);
    //     // else
    //     //     printf("    prev = NULL");
    //     stack_a = stack_a->next;
    // }
    // printf("\n");
    // printf("\n--Stack B--\n");
    // while (stack_b != NULL)
    // {
    //     printf("nbr_b = %d\n", stack_b->nbr);
    //     // if (stack_b->prev)
    //     //     printf("prev = %d\n", stack_b->prev->nbr);
    //     // else
    //     //     printf("prev = NULL\n");
    //     stack_b = stack_b->next;
    // }
    delete_list(stack_a);
}

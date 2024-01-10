/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2024/01/10 15:28:20 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    t_list  *stack_a;
    int nbr_count;
    char **str_array;

    stack_a = NULL;
    // create stack
    
    if (argc <= 1)
        return(-1);
    if (argc >= 2)
    {   
        i = 1;
	    while (argv[i])
	    {
            if (count_words(argv[i]) > 1)
            {
                str_array = ft_split(argv[i], ' ');
                j = 0;
                while (str_array[j])
                {
                    check_valid_arg(str_array[j], stack_a);
                    ft_lstadd_back_d(&stack_a, ft_lstnew_d(ft_atoi(str_array[j])));
                    free(str_array[j]);
                    j++;
                }
                free(str_array[j]);
            }
            else if (count_words(argv[i]) == 1)
            {
                check_valid_arg(argv[i], stack_a);
                if (argc >= 3)
                    ft_lstadd_back_d(&stack_a, ft_lstnew_d(ft_atoi(argv[i])));
            }
            else if (count_words(argv[i]) == 0)
                free_n_exit(stack_a);
            i++;
	    }
    }

    // ---------------------------------------------
    check_duplicates(stack_a); // ERROR CHECKING
    if (is_sorted(stack_a))
        exit (-1);

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

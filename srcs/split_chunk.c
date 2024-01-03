/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/03 13:41:12 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_max_index(t_list *chunk)
{
    int	max_index;

	max_index = chunk->index;
	chunk = chunk->next;
	while (chunk)
	{
		if (chunk->index > max_index)
			max_index = chunk->index;
		chunk = chunk->next;
	}
	return (max_index);
}

int	find_min_index(t_list *chunk)
{
	int	min_index;

	min_index = chunk->index;
	chunk = chunk->next;
	while (chunk)
	{
		if (chunk->index < min_index)
			min_index = chunk->index;
		chunk = chunk->next;
	}
	return (min_index);
}



void partition(t_list **stack_a, t_list **stack_b)
{
    int small_pivot;
    int large_pivot;
    int max_index;
    int min_index;
    
    small_pivot = max_index - (max_index - min_index) * (1.0 / 3);
    large_pivot = max_index - (max_index - min_index) * (2.0 / 3);
    
    // t_list *stack;
    // stack = *stack_a;
    while (*stack_a) 
    {
        if ((*stack_a)->index <= small_pivot) // MIN
			
        if ((*stack_a)->index > small_pivot && (*stack_a)->index <= large_pivot) // MID 
        if ((*stack_a)->index > large_pivot) // MAX
			
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/03 14:33:15 by sting            ###   ########.fr       */
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

void set_split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = BOT_A;
	}
	else if (loc == BOT_A)
	{
		min->loc = BOT_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOT_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
	else if (loc == BOT_B)
	{
		min->loc = TOP_B;
		mid->loc = BOT_A;
		max->loc = TOP_A;
	}
}

void partition(t_list **stack_a, t_list **stack_b, enum e_loc cur_loc)
{
    int small_pivot;
    int large_pivot;
    int max_index;
    int min_index;
	t_split_dest *sd;
    
    small_pivot = max_index - (max_index - min_index) * (1.0 / 3);
    large_pivot = max_index - (max_index - min_index) * (2.0 / 3);
    
	set_split_loc(cur_loc, &(sd->min), &(sd->mid), &(sd->max));
	
    while (*stack_a) 
    {
        if ((*stack_a)->index <= small_pivot) // MIN
			
        if ((*stack_a)->index > small_pivot && (*stack_a)->index <= large_pivot) // MID 
        if ((*stack_a)->index > large_pivot) // MAX
			
    }
}
void quick_sort3()
{
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/04 16:46:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*starting_node(t_list *stack_a, t_list *stack_b, enum e_loc cur_loc) // TESTED
{
	t_list	*node;
	
	node = NULL; 
	if (cur_loc == TOP_A)
		node = stack_a;
	else if (cur_loc == BOT_A)
		node = ft_lstlast(stack_a);	
	else if (cur_loc == TOP_B)
		node = stack_b;
	else if (cur_loc == BOT_B)
		node = ft_lstlast(stack_b);
	return (node);
}

int find_max_index(t_list *stack_a, t_list *stack_b, enum e_loc cur_loc, int cur_chunk_size) // TESTED
{	
	t_list *node;
	int	max_index;
	
	node = NULL; // ??
	node = starting_node(stack_a, stack_b, cur_loc);	
	max_index = node->index;
	
	if (cur_loc == TOP_A || cur_loc == TOP_B)
	{
		while (cur_chunk_size-- && node)
		{
			if (node->index > max_index)
				max_index = node->index;
			node = node->next;
		}
	}
	else if (cur_loc == BOT_A || cur_loc == BOT_B)
	{
		while (cur_chunk_size-- && node)
		{
			if (node->index > max_index)
				max_index = node->index;
			node = node->prev;
		}
	}
	return (max_index);
}


void set_split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max) // TESTED
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

void init_chunk_size(t_split_dest *dest) // TESTED
{
	dest->min.size = 0;
	dest->mid.size = 0;
	dest->max.size = 0;
}

void partition(t_list **stack_a, t_list **stack_b, enum e_loc cur_loc, int cur_chunk_size)
{
    int small_pivot;
    int large_pivot;
    int max_index;
	t_split_dest *dest; // create new set of split_dest for each partition
	t_list *node;
   
	dest = (t_split_dest *)malloc(sizeof(t_split_dest));
    max_index = find_max_index(*stack_a, *stack_b, cur_loc, cur_chunk_size);
	// printf("max_index: %i\n", max_index);
    small_pivot = max_index - cur_chunk_size * (2.0 / 3);
    large_pivot = max_index - cur_chunk_size * (1.0 / 3);
	// printf("small_pv: %i\n large_pv: %i\n", small_pivot, large_pivot);
    
	set_split_loc(cur_loc, &(dest->min), &(dest->mid), &(dest->max));
	// printf("min->loc: %i\n mid->loc: %i\n max->loc: %i\n", dest->min.loc, dest->mid.loc, dest->max.loc);
	init_chunk_size(dest);

    while (cur_chunk_size) // include node ?? 
	{
		// printf("check partition\n");
		node = starting_node(*stack_a, *stack_b, cur_loc);
			
      	if (node->index > large_pivot) // MAX
		{
			move_from_to(cur_loc, dest->max.loc, stack_a, stack_b);	
			dest->max.size++;
			printf("max_nb: %i\n", node->nbr);
		}
        else if (node->index > small_pivot && node->index <= large_pivot) // MID 
		{
			move_from_to(cur_loc, dest->mid.loc, stack_a, stack_b);	
			dest->mid.size++;			
			printf("mid_nb: %i\n", node->nbr);
		}
        else if (node->index <= small_pivot) // MIN
		{
			move_from_to(cur_loc, dest->min.loc, stack_a, stack_b);	
			dest->min.size++;
			printf("min_nb: %i\n", node->nbr);
		}	
		cur_chunk_size--; // ?? risky if somehow didn't enter any if statement
    }
	printf("min->size: %i\n mid->size: %i\n max->size: %i\n", dest->min.size, dest->mid.size, dest->max.size);
	free(dest);
}
// void quick_sort3()
// {
	
// }
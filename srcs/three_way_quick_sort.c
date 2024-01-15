/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_way_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/15 16:35:10 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*starting_node(t_stack *stack_a, t_stack *stack_b, enum e_loc cur_loc)
{
	t_stack	*node;

	node = NULL;
	if (cur_loc == TOP_A)
		node = stack_a;
	else if (cur_loc == BOT_A)
		node = ft_lstlast_d(stack_a);
	else if (cur_loc == TOP_B)
		node = stack_b;
	else if (cur_loc == BOT_B)
		node = ft_lstlast_d(stack_b);
	return (node);
}

void	move_nbr_based_on_index(t_pv pivot, t_split_dest *dest,
		t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = starting_node(*stack_a, *stack_b, dest->cur_loc);
	if (node->index > pivot.large)
	{
		move_from_to(dest->cur_loc, dest->max.loc, stack_a, stack_b);
		dest->max.size++;
	}
	else if (node->index > pivot.small && node->index <= pivot.large)
	{
		move_from_to(dest->cur_loc, dest->mid.loc, stack_a, stack_b);
		dest->mid.size++;
	}
	else if (node->index <= pivot.small)
	{
		move_from_to(dest->cur_loc, dest->min.loc, stack_a, stack_b);
		dest->min.size++;
	}
}

t_split_dest	*split_to_3_chunks(t_stack **stack_a, t_stack **stack_b,
		enum e_loc cur_loc, int cur_chunk_size)
{
	int				max_index;
	t_pv			pivot;
	t_split_dest	*dest;

	dest = (t_split_dest *)malloc(sizeof(t_split_dest));
	max_index = find_max_index(*stack_a, *stack_b, cur_loc, cur_chunk_size);
	pivot.small = max_index - cur_chunk_size * (2.0 / 3);
	pivot.large = max_index - cur_chunk_size * (1.0 / 3);
	if (cur_loc == BOT_A && ft_lstsize_d(*stack_a) == cur_chunk_size)
		cur_loc = TOP_A;
	if (cur_loc == BOT_B && ft_lstsize_d(*stack_b) == cur_chunk_size)
		cur_loc = TOP_B;
	dest->cur_loc = cur_loc;
	set_split_loc(cur_loc, &(dest->min), &(dest->mid), &(dest->max));
	init_chunk_size(dest);
	while (cur_chunk_size)
	{
		move_nbr_based_on_index(pivot, dest, stack_a, stack_b);
		cur_chunk_size--;
	}
	return (dest);
}

void	quick_sort_3way(t_stack **stack_a, t_stack **stack_b,
		enum e_loc cur_loc, int cur_chunksize)
{
	t_split_dest	*dest;

	if (cur_chunksize == 1)
		move_from_to(cur_loc, TOP_A, stack_a, stack_b);
	else if (cur_chunksize == 2)
	{
		move_from_to(cur_loc, TOP_A, stack_a, stack_b);
		move_from_to(cur_loc, TOP_A, stack_a, stack_b);
		if ((*stack_a)->nbr > ((*stack_a)->next)->nbr)
			sa(*stack_a);
	}
	else if (cur_chunksize > 2)
	{
		dest = split_to_3_chunks(stack_a, stack_b, cur_loc, cur_chunksize);
		quick_sort_3way(stack_a, stack_b, dest->max.loc, dest->max.size);
		quick_sort_3way(stack_a, stack_b, dest->mid.loc, dest->mid.size);
		quick_sort_3way(stack_a, stack_b, dest->min.loc, dest->min.size);
		free(dest);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/11 09:00:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_index(t_list *stack_a, t_list *stack_b, enum e_loc cur_loc,
		int cur_chunk_size)
{
	t_list	*node;
	int		max_index;

	node = NULL;
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

void	set_split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
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

void	init_chunk_size(t_split_dest *dest)
{
	dest->min.size = 0;
	dest->mid.size = 0;
	dest->max.size = 0;
}

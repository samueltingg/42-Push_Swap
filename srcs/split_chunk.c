/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/10 16:40:42 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*starting_node(t_list *stack_a, t_list *stack_b, enum e_loc cur_loc)
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

t_split_dest	*partition(t_list **stack_a, t_list **stack_b,
		enum e_loc cur_loc, int cur_chunk_size)
{
	int				small_pivot;
	int				large_pivot;
	int				max_index;
	t_split_dest	*dest;
	t_list			*node;

	dest = (t_split_dest *)malloc(sizeof(t_split_dest));
	max_index = find_max_index(*stack_a, *stack_b, cur_loc, cur_chunk_size);
	small_pivot = max_index - cur_chunk_size * (2.0 / 3);
	large_pivot = max_index - cur_chunk_size * (1.0 / 3);
	if (cur_loc == BOT_A && ft_lstsize(*stack_a) == cur_chunk_size)
		cur_loc = TOP_A;
	if (cur_loc == BOT_B && ft_lstsize(*stack_b) == cur_chunk_size)
		cur_loc = TOP_B;
	set_split_loc(cur_loc, &(dest->min), &(dest->mid), &(dest->max));
	init_chunk_size(dest);
	while (cur_chunk_size)
	{
		node = starting_node(*stack_a, *stack_b, cur_loc);
		if (node->index > large_pivot)
		{
			move_from_to(cur_loc, dest->max.loc, stack_a, stack_b);
			dest->max.size++;
		}
		else if (node->index > small_pivot && node->index <= large_pivot)
		{
			move_from_to(cur_loc, dest->mid.loc, stack_a, stack_b);
			dest->mid.size++;
		}
		else if (node->index <= small_pivot)
		{
			move_from_to(cur_loc, dest->min.loc, stack_a, stack_b);
			dest->min.size++;
		}
		cur_chunk_size--;
	}
	return (dest);
}

void	quick_sort3(t_list **stack_a, t_list **stack_b, enum e_loc cur_loc,
		int cur_chunksize)
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
		dest = partition(stack_a, stack_b, cur_loc, cur_chunksize);
		quick_sort3(stack_a, stack_b, dest->max.loc, dest->max.size);
		quick_sort3(stack_a, stack_b, dest->mid.loc, dest->mid.size);
		quick_sort3(stack_a, stack_b, dest->min.loc, dest->min.size);
		free(dest);
	}
}

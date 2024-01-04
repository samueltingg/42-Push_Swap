/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/04 14:20:49 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	move_from_to(t_list **stack_a, t_list **stack_b, enum e_loc from, enum e_loc to)
{
	if (from == TOP_A)
		move_from_top_a(stack_a, stack_b, to);
	else if (from == TOP_B)
		move_from_top_b(stack_a, stack_b, to);
	else if (from == BOT_A)
		move_from_bottom_a(stack_a, stack_b, to);
	else if (from == BOT_B)
		move_from_bottom_b(stack_a, stack_b, to);
	return (1);
}

void move_from_top_a(t_list **stack_a, t_list **stack_b, enum e_loc to)
{
	if (to == BOT_A)
		ra(stack_a);
	else if (to == TOP_B) 
		pb(stack_a, stack_b);
	else if (to == BOT_B)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void move_from_top_b(t_list **stack_a, t_list **stack_b, enum e_loc to)
{
	if (to == TOP_A)
		pa(stack_b, stack_a);
	else if (to == BOT_B)
		rb(stack_b);
	else if (to == BOT_A)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}	
}

void move_from_bottom_a(t_list **stack_a, t_list **stack_b, enum e_loc to)
{
	if (to == TOP_A)
		rra(stack_a);
	else if (to == TOP_B)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (to == BOT_B)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void move_from_bottom_b(t_list **stack_a, t_list **stack_b, enum e_loc to)
{
	if (to == TOP_B)
		rrb(stack_b);
	else if (to == TOP_A)
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
	}
	else if (to == BOT_A)
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
		ra(stack_a);
	}
}
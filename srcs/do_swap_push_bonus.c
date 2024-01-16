/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap_push_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:40 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 15:13:08 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	do_sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	do_sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

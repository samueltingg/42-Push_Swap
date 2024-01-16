/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:45 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 15:13:19 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rra(t_stack **stack_a)
{
	if ((*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
}

void	do_rrb(t_stack **stack_b)
{
	if ((*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
}
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

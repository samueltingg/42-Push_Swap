/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:45 by sting             #+#    #+#             */
/*   Updated: 2024/01/22 12:37:04 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/checker_bonus.h"

void	do_ra(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
}

void	do_rb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next == NULL)
		return ;
	if (*stack_b && (*stack_b)->next == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:45 by sting             #+#    #+#             */
/*   Updated: 2024/01/22 12:34:05 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return (-1);
	if (!(stack->next))
		return (-1);
	tmp = (stack)->nbr;
	(stack)->nbr = ((stack)->next)->nbr;
	((stack)->next)->nbr = tmp;
	return (0);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

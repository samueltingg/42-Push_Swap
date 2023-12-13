/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:37:48 by sting             #+#    #+#             */
/*   Updated: 2023/12/13 12:09:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	if (first->nbr > second->nbr && first->nbr > third->nbr)
		ra(stack);
	else if (second->nbr > first->nbr && second->nbr > third->nbr)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(*stack);
}

static int	find_smallest(t_list *stack)
{
	int	smallest;

	smallest = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr < smallest)
			smallest = stack->nbr;
		stack = stack->next;
	}
	return (smallest);
}

static int	if_smallest_in_bottom_half(t_list *stack, int smallest)
{
	int	lstsize;
	int	half;

	half = 0;
	lstsize = ft_lstsize(stack);
	while (half < lstsize / 2)
	{
		stack = stack->next;
		half++;
	}
	if (lstsize == 5 && stack->nbr == smallest)
		return (0);
	while (half < lstsize)
	{
		if (stack->nbr == smallest)
			return (1);
		stack = stack->next;
		half++;
	}
	return (0);
}
// line 59: smallest nb in middle is not counted

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int	smallest;

	while (*stack_a)
	{
		smallest = find_smallest(*stack_a);
		if (if_smallest_in_bottom_half(*stack_a, smallest))
		{
			while ((*stack_a)->nbr != smallest)
				rra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != smallest)
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_b, stack_a);
}

void	sort4_or_5(t_list **stack_a, t_list **stack_b, int nbr_count)
{
	int	smallest;
	int	i;

	i = nbr_count - 3;
	while (i--)
	{
		smallest = find_smallest(*stack_a);
		if (if_smallest_in_bottom_half(*stack_a, smallest))
		{
			while ((*stack_a)->nbr != smallest)
				rra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != smallest)
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort3(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a);
}

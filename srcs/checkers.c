/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:04 by sting             #+#    #+#             */
/*   Updated: 2024/01/11 10:08:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_n_exit(t_list *ptr)
{
	ft_putstr_fd("Error\n", 2);
	delete_list(ptr);
	exit(-1);
}

void	check_valid_arg(char *str, t_list *stack)
{
	long	nbr;
	int		i;

	i = 0;
	if (str[i] == '\0')
		free_n_exit(stack);
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			free_n_exit(stack);
		i++;
	}
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		free_n_exit(stack);
}

void	check_duplicates(t_list *head)
{
	t_list	*runner;

	while (head)
	{
		runner = (head)->next;
		while (runner)
		{
			if (head->nbr == runner->nbr)
				free_n_exit(head);
			runner = runner->next;
		}
		head = head->next;
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*next;

	while (stack)
	{
		next = stack->next;
		if (next && stack->nbr > next->nbr)
			return (0);
		stack = next;
	}
	return (1);
}

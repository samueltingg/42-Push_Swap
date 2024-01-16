/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 17:17:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_words(char const *str)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{ 
		if (*str != ' ' && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == ' ')
			flag = 1;
		str++;
	}
	return (count);
}

void	check_n_add_arg_to_stack(int argc, char **argv, int i,
		t_stack **stack_a)
{
	char	**str_array;
	int		j;

	if (count_words(argv[i]) > 1)
	{
		str_array = ft_split(argv[i], ' ');
		j = 0;
		while (str_array[j])
		{
			check_valid_arg(str_array[j], *stack_a);
			ft_lstadd_back_d(stack_a, ft_lstnew_d(ft_atoi(str_array[j])));
			free(str_array[j]);
			j++;
		}
		free(str_array[j]);
	}
	else if (count_words(argv[i]) == 1)
	{
		check_valid_arg(argv[i], *stack_a);
		if (argc >= 3)
			ft_lstadd_back_d(stack_a, ft_lstnew_d(ft_atoi(argv[i])));
	}
	else if (count_words(argv[i]) == 0)
		free_n_exit(*stack_a);
}
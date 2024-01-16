/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 11:14:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int main(int argc, char **argv)
{
    int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char *input;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (-1);
	if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{
			check_n_add_arg_to_stack(argc, argv, i, &stack_a);
			i++;
		}
	}
	check_duplicates(stack_a);

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break;
		do_instruction_based_on_input(input, stack_a, stack_b);
		
	}
	
	delete_stack(stack_a);
}
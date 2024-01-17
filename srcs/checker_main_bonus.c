/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2024/01/17 09:28:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	do_instruction_if_valid(const char *instruction, int strlen,
		t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instruction, "sa\n", strlen) == 0)
		do_sa(*stack_a);
	else if (ft_strncmp(instruction, "sb\n", strlen) == 0)
		do_sb(*stack_b);
	else if (ft_strncmp(instruction, "ss\n", strlen) == 0)
		do_ss(*stack_a, *stack_b);
	else if (ft_strncmp(instruction, "pa\n", strlen) == 0)
		do_pa(stack_b, stack_a);
	else if (ft_strncmp(instruction, "pb\n", strlen) == 0)
		do_pb(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra\n", strlen) == 0)
		do_ra(stack_a);
	else if (ft_strncmp(instruction, "rb\n", strlen) == 0)
		do_rb(stack_b);
	else if (ft_strncmp(instruction, "rr\n", strlen) == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra\n", strlen) == 0)
		do_rra(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", strlen) == 0)
		do_rrb(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", strlen) == 0)
		do_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	do_instruction_based_on_input(char *instruction, t_stack **stack_a,
		t_stack **stack_b)
{
	size_t	strlen;
	int		valid;

	strlen = ft_strlen(instruction);
	valid = do_instruction_if_valid((const char *)instruction, strlen, stack_a,
			stack_b);
	if (!valid)
	{
		delete_stack(*stack_b);
		free(instruction);
		free_n_exit(*stack_a);
	}
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		do_instruction_based_on_input(input, stack_a, stack_b);
		free(input);
	}
	if (is_sorted(*stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else if (!is_sorted(*stack_a) || *stack_b != NULL)
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	checker(&stack_a, &stack_b);
	ft_printf("input address: %p\n", stack_a);
	delete_stack(stack_a);
	delete_stack(stack_b);
	exit(0);
}

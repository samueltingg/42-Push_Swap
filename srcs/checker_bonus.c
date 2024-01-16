/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:50 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 15:23:42 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	do_instruction_based_on_input(char *input, t_stack **stack_a,
		t_stack **stack_b)
{
	size_t		strlen;
	const char	*instruction;

	instruction = (const char *)input;
	strlen = ft_strlen(instruction);
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
	{
		delete_stack(*stack_b);
		free_n_exit(*stack_a);
	}
}

static int	count_words(char const *str)
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

static void	check_n_add_arg_to_stack(int argc, char **argv, int i,
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

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

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
			break ;
		do_instruction_based_on_input(input, &stack_a, &stack_b);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK");
	else if (!is_sorted(stack_a) || stack_b != NULL)
		ft_printf("KO");
	delete_stack(stack_a);
}

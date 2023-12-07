/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:18:18 by sting             #+#    #+#             */
/*   Updated: 2023/12/07 13:30:33 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// utils
long	ft_atol(const char *str);
void	delete_list(t_list *list);

// Checking
void	check_nbr_valid(char *str, t_list *stack);
void	check_duplicates(t_list *head);
int is_sorted(t_list *stack);

// instructions
void swap(t_list *stack);
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ss(t_list *stack_a, t_list *stack_b);

#endif
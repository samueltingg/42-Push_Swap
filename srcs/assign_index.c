/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:08:25 by sting             #+#    #+#             */
/*   Updated: 2024/01/02 15:51:13 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void assign_index(t_list *stack)
{
	t_list *tmp1;
	t_list *tmp2;
	int	count;
	
	tmp1 = stack;
	while (tmp1)
	{
		count = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1->nbr > tmp2->nbr) 
				count++;
			tmp2 = tmp2->next;
		}
		tmp1->index = count + 1;
		tmp1 = tmp1->next;
	}
}

/*
- index = amount of nbrs less than current nbr + 1
*/



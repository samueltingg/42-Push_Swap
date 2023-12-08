/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:58 by sting             #+#    #+#             */
/*   Updated: 2023/12/08 13:34:43 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int i;
	long sign;
	long result;

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

void	delete_list(t_list *list)
{
	t_list	*next_node;

	while (list)
	{
		next_node = list->next;
		free (list);
		list = next_node;
	}
}

t_list	*ft_lstnew_d(int nbr)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = NULL; // changes
	new_node->nbr = nbr;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_d(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = ft_lstlast(*lst); // changes
	(ft_lstlast(*lst))->next = new;
}
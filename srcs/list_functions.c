/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:58 by sting             #+#    #+#             */
/*   Updated: 2024/01/10 16:23:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_list(t_list *list)
{
	t_list	*next_node;

	while (list)
	{
		next_node = list->next;
		free(list);
		list = next_node;
	}
}

t_list	*ft_lstnew_d(int nbr)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	new_node->prev = NULL;
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
	new->prev = ft_lstlast(*lst);
	(ft_lstlast(*lst))->next = new;
}

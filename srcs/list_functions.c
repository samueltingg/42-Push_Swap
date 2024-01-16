/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:56:58 by sting             #+#    #+#             */
/*   Updated: 2024/01/16 16:34:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_stack(t_stack *list)
{
	t_stack	*next_node;

	if (list == NULL)
		return ;
	while (list)
	{
		next_node = list->next;
		free(list);
		list = next_node;
	}
}

t_stack	*ft_lstnew_d(int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
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

void	ft_lstadd_back_d(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = ft_lstlast_d(*lst);
	(ft_lstlast_d(*lst))->next = new;
}

int	ft_lstsize_d(t_stack *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack	*ft_lstlast_d(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

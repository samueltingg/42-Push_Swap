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

void	delete_list(t_list **list)
{
	t_list	*next_node;

	while (*list)
	{
		next_node = (*list)->next;
		// free((*list)->nbr);
		free(*list);
		*list = next_node;
	}
}
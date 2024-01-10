#include "../push_swap.h"

void    free_n_exit(t_list *ptr) // use later
{            
    ft_printf("Error\n");
    delete_list(ptr);
    exit(-1);
}

void check_valid_arg(char *str, t_list *stack)
{
    long nbr;
    if (*str == '\0')
        free_n_exit(stack);

    while (*str)
    {
        if (*str == '-')
            str++;
        if (!ft_isdigit(*str)) 
            free_n_exit(stack);   
        str++;
    }
    nbr = ft_atol(str);
    if (nbr > INT_MAX || nbr < INT_MIN)
        free_n_exit(stack);
}
void check_duplicates(t_list *head)
{
    t_list  *runner;
    while (head)
    {
        runner = (head)->next;
        while (runner)
        {
            if (head->nbr == runner->nbr)
                free_n_exit(head);
            runner = runner->next;
        }
        head = head->next;
    }
}

int is_sorted(t_list *stack)
{
    t_list  *next;

    while (stack)
    {
        next = stack->next;
        if (next && stack->nbr > next->nbr)
            return (0);
        stack = next;
   }
    return (1);
}
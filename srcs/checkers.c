#include "../push_swap.h"

void check_nbr_valid(char *str, t_list *stack)
{
    long nbr;

    while (*str)
    {
        if (*str == '-')
            str++;
        if (!ft_isdigit(*str)) 
        {
            ft_printf("%s\n", "Error");
            delete_list(stack);
            exit(-1);
        }   
        str++;
    }
    nbr = ft_atol(str);
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        ft_printf("%s\n", "Error");
        delete_list(stack);
        exit(-1);
    }
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
            {
                delete_list(head);
                ft_printf("%s\n", "Error");
                exit(-1);
            }
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
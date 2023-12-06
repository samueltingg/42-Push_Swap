#include "../push_swap.h"

void check_nbr_valid(char *str)
{
    long nbr;

    nbr = ft_atol(str);
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        ft_printf("%s\n", "Error");
        exit(-1);
    }
    while (*str)
    {
        if (!ft_isdigit(*str)) 
        {
            ft_printf("%s\n", "Error");
            exit(-1);
        }   
        str++;
    }
}
void check_duplicates(t_list **head)
{
    t_list  *runner;
    while ((*head))
    {
        runner = ((*head))->next;
        while (runner)
        {
            if ((*head)->nbr == runner->nbr)
            {
                delete_list(head);
                ft_printf("%s\n", "Error");
                // exit(-1);
            }
            runner = runner->next;
        }
        (*head) = (*head)->next;
    }
}

int main(int argc, char **argv)
{
    int i;
    t_list  *stack;
    t_list  *new;

    stack = NULL;
    if (argc <= 2)
        return (-1);
    
    // create stack
    i = 1;
    while (argv[i] != NULL) 
    {
        check_nbr_valid(argv[i]); // ERROR CHECKING
        new = ft_lstnew(ft_atoi(argv[i])); // malloc
        ft_lstadd_back(&stack, new);
        i++;
    }
    check_duplicates(&stack); // ERROR CHECKING

    // check created stack
    while (stack != NULL)
    {
        printf("nbr = %d\n", stack->nbr);    
        stack = stack->next;
    }
}

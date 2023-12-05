#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_list  *stack;
    t_list  *next;
    t_list  *new;

    if (argc <= 2) // if 1 or lesser numbers
        return (-1);
    
    // create stack
    i = 0;
    while (argv[i])
    {
        new = ft_lstnew(argv[i]);
        next = new->next;
        ft_lstadd_back(&stack, new);
        i++;
    }

    while (stack != NULL)
    {
        ft_printf("nbr = %s", stack->nbr);    
        stack = stack->next;
    }
}
#include "push_swap.h"

t_node    *new_node(int number)
{
    t_node    *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->number = number;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void    node_add_back(t_node **node, t_node    *new)
{
    t_node    *temp;

    if (!node || !new)
        return ;
    if (!*(node))
    {
        *node = new;
        return ;
    }
    temp = *node;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

#include "push_swap.h"

t_node    *ft_llstnew(int number)
{
	t_node    *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void    ft_llstaddback(t_node **head, t_node *node)
{
	t_node    *temp;

	if (!head || !node)
		return ;
	if (!*(head))
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	node->prev = temp;
}

void	ft_llstclear(t_node **head)
{
	t_node	*next;

	if (!head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}

int	ft_llstsize(t_node *head)
{
	int size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

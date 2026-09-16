#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_node	*head;
	t_node	*tmp;

	if (argc <= 1)
		return (0);
	head = create_struct(argv);
	if (!head)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	/*
	 radix_sort(&head);
	tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
	*/
	return (0);
}
*/
t_node *handle_fail(t_node **head)
{
	ft_llstclear(head);
	return (NULL);
}

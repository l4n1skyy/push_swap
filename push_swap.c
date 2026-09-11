#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node	*head;

	if (argc <= 1)
		return (0);
	head = create_struct(argv);
	if (!head)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

t_node *handle_fail(t_node **head)
{
	ft_llstclear(head);
	return (NULL);
}

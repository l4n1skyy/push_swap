#include "libft/libft.h"
#include "push_swap.h"

static int	add_number(t_node **head, char *str)
{
	t_node	*node;

	node = ft_llstnew(ft_atoi_long(str));
	if (!node)
		return (0);
	ft_llstaddback(head, node);
	if (check_duplicate(*head))
		return (0);
	return (1);
}
static void	assign_ranks(t_node *head)
{
	t_node	*outer;
	t_node	*inner;
	int		counter;

	outer = head;
	inner = head;
	while (outer)
	{
		counter = 0;
		inner = head;
		while (inner)
		{
			if (outer->number > inner->number)
				counter++;
			inner = inner->next;
		}
		outer->rank = counter;
		outer = outer->next;
	}
}

t_node	*create_struct(char **argv)
{
	t_node	*head;

	head = NULL;
	while (*argv)
	{
		if (!is_valid_number(*argv))
			return (handle_fail(&head));
		if (!is_in_range(*argv))
			return (handle_fail(&head));
		if (!add_number(&head, *argv))
			return (handle_fail(&head));
		argv++;
	}
	assign_ranks(head);
	return (head);
}

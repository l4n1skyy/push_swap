#include "libft/libft.h"
#include "push_swap.h"

static int check_duplicate(t_node *head);
static long ft_atoi_long(char *s);

t_node *create_struct(char **argv)
{
	t_node	*head;
	t_node	*node;
	char	*read;
	long	number;

	argv++;
	head = NULL;
	while (*argv)
	{
		// check empty
		read = *argv;
		if (*read == '\0')
			return (handle_fail(&head));

		// check digit/sign
		read = *argv;
		if (*read == '-' || *read == '+')
			read++;
		while (ft_isdigit(*read))
			read++;
		if (*read || !ft_isdigit(*(read - 1)))
			return (handle_fail(&head));

		// check range
		read = *argv;
		number = ft_atoi_long(*argv);
		if (number < -2147483648 || number > 2147483647)
			return (handle_fail(&head));

		// create node
		node = ft_llstnew(number);
		if (!node)
			return (handle_fail(&head));

		// add node to list
		ft_llstaddback(&head, node);

		// check duplicate
		if (check_duplicate(head))
			return (handle_fail(&head));

		argv++;
	}
	return (head);
}

static int check_duplicate(t_node *head)
{
	t_node *rest;

	while (head && head->next)
	{
		rest = head->next;
		while (rest)
		{
			if (head->number == rest->number)
				return (1);
			rest = rest->next;
		}
		head = head->next;
	}
	return (0);
}

static long ft_atoi_long(char *s)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return ((n * sign));
}

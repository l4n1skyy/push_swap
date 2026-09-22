/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:57:58 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/22 14:03:32 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_operation(char *line, t_node **a, t_node **b,
		t_bench *bench)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, bench);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, bench);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, bench);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(b, a, bench);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, bench);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, bench);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, bench);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, bench);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, bench);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, bench);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, bench);
	else
		return (0);
	return (1);
}

static int	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_bench	bench;
	char	*line;

	if (argc < 2)
		return (0);
	a = create_struct(argv + 1);
	if (!a)
		return (handle_error());
	b = NULL;
	bench = (t_bench){0};
	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(line, &a, &b, &bench))
		{
			free(line);
			ft_llstclear(&a);
			ft_llstclear(&b);
			return (handle_error());
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_llstclear(&a);
	ft_llstclear(&b);
	return (0);
}

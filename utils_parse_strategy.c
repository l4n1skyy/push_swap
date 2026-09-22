/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:53:45 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/22 14:41:38 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_strategy(char *argv)
{
	if (ft_strncmp(argv, "--simple", 9) == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strncmp(argv, "--medium", 9) == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strncmp(argv, "--complex", 10) == 0)
		return (STRATEGY_COMPLEX);
	if (ft_strncmp(argv, "--adaptive", 11) == 0)
		return (STRATEGY_ADAPTIVE);
	return (-1);
}

static int	process_option(char *arg, int *strategy, int *benchmark,
		int *strategy_found)
{
	int	current;

	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (*benchmark)
			return (0);
		*benchmark = 1;
	}
	else
	{
		current = parse_strategy(arg);
		if (current == -1 || *strategy_found)
			return (0);
		*strategy = current;
		*strategy_found = 1;
	}
	return (1);
}

static int	adaptive_sort(t_node **head, float disorder, t_bench *bench)
{
	int	size;

	size = ft_llstsize(*head);
	if (disorder < 0.2 || size < 6)
	{
		simple_sort(head, size, bench);
		return (STRATEGY_SIMPLE);
	}
	if (disorder >= 0.5)
	{
		complex_sort(head, bench);
		return (STRATEGY_COMPLEX);
	}
	medium_sort(head, bench);
	return (STRATEGY_MEDIUM);
}

char	**parse_options(char **argv, int *strategy, int *benchmark)
{
	int	strategy_found;

	*strategy = STRATEGY_ADAPTIVE;
	*benchmark = 0;
	strategy_found = 0;
	argv++;
	while (*argv && (*argv)[0] == '-' && (*argv)[1] == '-')
	{
		if (!process_option(*argv, strategy, benchmark, &strategy_found))
			return (NULL);
		argv++;
	}
	return (argv);
}

int	select_strategy(t_node **head, int strategy, float disorder,
		t_bench *bench)
{
	if (disorder == 0.0f)
	{
		if (strategy == STRATEGY_ADAPTIVE)
			return (STRATEGY_SIMPLE);
		return (strategy);
	}
	if (strategy == STRATEGY_ADAPTIVE)
		return (adaptive_sort(head, disorder, bench));
	if (strategy == STRATEGY_SIMPLE)
		simple_sort(head, ft_llstsize(*head), bench);
	else if (strategy == STRATEGY_MEDIUM)
		medium_sort(head, bench);
	else if (strategy == STRATEGY_COMPLEX)
		complex_sort(head, bench);
	else
		return (-1);
	return (strategy);
}

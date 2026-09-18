/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:48:29 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 18:01:15 by jia-xcho         ###   ########.fr       */
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

char	**parse_options(char **argv, int *strategy, int *benchmark)
{
	int	strategy_found;
	int	current;

	*strategy = STRATEGY_ADAPTIVE;
	*benchmark = 0;
	strategy_found = 0;
	argv++;
	while (*argv && (*argv)[0] == '-' && (*argv)[1] == '-')
	{
		if (ft_strncmp(*argv, "--bench", 8) == 0)
		{
			if (*benchmark)
				return (NULL);
			*benchmark = 1;
		}
		else
		{
			current = parse_strategy(*argv);
			if (current == -1 || strategy_found)
				return (NULL);
			*strategy = current;
			strategy_found = 1;
		}
		argv++;
	}
	return (argv);
}

int	adaptive_sort(t_node **head, float disorder, t_bench *bench)
{
	if (disorder < 0.2)
	{
		minmax_sort(head, bench);
		return (STRATEGY_SIMPLE);
	}
	else
	{
		radix_sort(head, bench);
		return (STRATEGY_COMPLEX);
	}
	// else
	// {
	// 	medium_sort(head, bench);
	// 	return (STRATEGY_MEDIUM);
	// }
}

int	select_strategy(t_node **head, int strategy, float disorder, t_bench *bench)
{
	if (strategy == STRATEGY_SIMPLE)
	{
		minmax_sort(head, bench);
		return (STRATEGY_SIMPLE);
	}
	// else if (strategy == STRATEGY_MEDIUM)
	// {
	// 	medium_sort(head);
	// 	return (STRATEGY_MEDIUM);
//	}
	else if (strategy == STRATEGY_COMPLEX)
	{
		radix_sort(head, bench);
		return (STRATEGY_COMPLEX);
	}
	return (adaptive_sort(head, disorder, bench));
}


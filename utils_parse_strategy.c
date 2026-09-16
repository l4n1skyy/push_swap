/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:48:29 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/16 23:14:44 by jia-xcho         ###   ########.fr       */
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
		if (ft_strncmp(*argv, "--benchmark", 11) == 0)
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
void	adaptive_sort(t_node **head)
{
	float	disorder;
	int		strategy;

	disorder = compute_disorder(*head);
	if (disorder < 0.2)
		strategy = STRATEGY_SIMPLE;
	else if (disorder >= 0.5)
		strategy = STRATEGY_COMPLEX;
	else
		strategy = STRATEGY_MEDIUM;
	select_strategy(head, strategy);
}

void	select_strategy(t_node **head, int strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		selection_sort(head);
	// else if (strategy == STRATEGY_MEDIUM)
	// 	medium_sort(head);
	else if (strategy == STRATEGY_COMPLEX)
		radix_sort(head);
	else if (strategy == STRATEGY_ADAPTIVE)
		adaptive_sort(head);
}


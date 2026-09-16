/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 23:07:55 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/16 23:14:42 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	char	*read;

	if (!str || *str == '\0')
		return (0);
	read = str;
	if (*read == '-' || *read == '+')
		read++;
	if (!ft_isdigit(*read))
		return (0);
	while (ft_isdigit(*read))
		read++;
	if (*read != '\0')
		return (0);
	return (1);
}

int	check_duplicate(t_node *head)
{
	t_node	*rest;

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

long	ft_atoi_long(char *s)
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
	return (n * sign);
}

int	is_in_range(char *str)
{
	long	number;

	number = ft_atoi_long(str);
	if (number < -2147483648 || number > 2147483647)
		return (0);
	return (1);
}

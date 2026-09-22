/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:17:09 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/22 11:18:17 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

t_node	*handle_fail(t_node **head)
{
	ft_llstclear(head);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*sub)
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && sub[j] && i + j < n && str[i + j] == sub[j])
			j++;
		if (!sub[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

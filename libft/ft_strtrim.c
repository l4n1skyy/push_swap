/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <a@b.c> */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dst;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && ft_in_set(s[start], set))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_in_set(s[end - 1], set))
		end--;
	dst = malloc(end - start + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

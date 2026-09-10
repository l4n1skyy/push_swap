/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static void	free_all(char **dst, int i)
{
	while (i >= 0)
	{
		free(dst[i]);
		i--;
	}
	free(dst);
}

static char	**ft_fill_split(char const *s, char c, char **dst, int words)
{
	int	i;
	int	len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		dst[i] = ft_substr(s, 0, len);
		if (!dst[i])
		{
			free_all(dst, i - 1);
			return (NULL);
		}
		s += len;
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		words;

	words = ft_count_words(s, c);
	dst = malloc((words + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	return (ft_fill_split(s, c, dst, words));
}

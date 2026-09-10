/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <a@b.c> */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*dst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/09/22 10:10:03 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	gnl_fail(char *buffer, char **stash);
static int	update_stash(char **stash, char *buffer, ssize_t bytes_read);
static int	buffer_read(int fd, char **stash);
static char	**ft_split_newline(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		**split;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash || !buffer_read(fd, &stash))
		return (NULL);
	split = ft_split_newline(stash);
	if (!split)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = split[0];
	free(stash);
	stash = split[1];
	free(split);
	return (line);
}

static int	buffer_read(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (ft_strchr(*stash, '\n'))
		return (1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (gnl_fail(buffer, stash));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!update_stash(stash, buffer, bytes_read))
			return (gnl_fail(buffer, stash));
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (gnl_fail(buffer, stash));
	free(buffer);
	return (1);
}

static int	update_stash(char **stash, char *buffer, ssize_t bytes_read)
{
	char	*new_stash;

	buffer[bytes_read] = '\0';
	new_stash = ft_strjoin(*stash, buffer);
	if (!new_stash)
		return (0);
	free(*stash);
	*stash = new_stash;
	return (1);
}

static int	gnl_fail(char *buffer, char **stash)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (0);
}

static char	**ft_split_newline(char *stash)
{
	char	**result;
	char	*newline_pos;
	int		len;

	if (!*stash)
		return (NULL);
	result = malloc(sizeof(char *) * 2);
	if (!result)
		return (NULL);
	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		len = newline_pos - stash + 1;
	else
		len = ft_strlen(stash);
	result[0] = ft_substr(stash, 0, len);
	result[1] = ft_substr(stash, len, ft_strlen(stash) - len);
	if (!result[0] || !result[1])
	{
		free(result[0]);
		free(result[1]);
		free(result);
		return (NULL);
	}
	return (result);
}

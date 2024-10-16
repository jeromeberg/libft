/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:02:44 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static int	ft_has_newline(char *str);
static int	ft_read(int fd, char **stash, char *buffer);
static char	*ft_extract_line(char *stash);
static char	*ft_update_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (!ft_read(fd, &stash, buffer))
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}

/* Read file until '\n' and append buffer to stash, update stash via pointer */
static int	ft_read(int fd, char **stash, char *buffer)
{
	ssize_t	rd;
	char	*tmp;

	rd = 1;
	while (!ft_has_newline(*stash) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(*stash);
			*stash = NULL;
			return (0);
		}
		buffer[rd] = '\0';
		tmp = *stash;
		if (!tmp)
			tmp = ft_strdup("");
		*stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	return (1);
}

/* Extract the line from stash up to '\n' */
static char	*ft_extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || *stash == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

/* Update stash */
static char	*ft_update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i);
	free(stash);
	return (new_stash);
}

/* Check if string contains '\n' */
static int	ft_has_newline(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

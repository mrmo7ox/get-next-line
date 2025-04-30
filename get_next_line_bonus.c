/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:05:07 by moel-oua          #+#    #+#             */
/*   Updated: 2024/11/23 10:42:18 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *source)
{
	char	*dup;
	int		len;

	if (!source)
		return (NULL);
	len = ft_strlen(source);
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy (dup, source, len);
	dup[len] = '\0';
	return (dup);
}

static char	*ft_join(char *checkpoint, char *next, int read_bytes)
{
	char	*tmp;

	next[read_bytes] = '\0';
	tmp = checkpoint;
	checkpoint = ft_strjoin(checkpoint, next);
	free(tmp);
	return (checkpoint);
}

static char	*ft_read_until_newline(int fd, char *checkpoint)
{
	char	*next;
	ssize_t	read_bytes;

	next = NULL;
	while (!ft_strchr(checkpoint, '\n'))
	{
		next = malloc((size_t)BUFFER_SIZE + 1);
		if (!next)
			return (free(checkpoint), checkpoint = NULL, NULL);
		read_bytes = read(fd, next, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free (next);
			if (read_bytes < 0)
				return (free(checkpoint), checkpoint = NULL, NULL);
			break ;
		}
		checkpoint = ft_join(checkpoint, next, read_bytes);
		if (checkpoint == NULL)
			return (free(next), NULL);
		free(next);
		next = NULL;
	}
	return (checkpoint);
}

char	*get_next_line(int fd)
{
	static char	*checkpoint[OPEN_MAX];
	char		*line;
	int			len;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(checkpoint[fd], '\n'))
		checkpoint[fd] = ft_read_until_newline(fd, checkpoint[fd]);
	if (!checkpoint[fd])
		return (NULL);
	len = 0;
	while (checkpoint[fd][len] != '\n' && checkpoint[fd][len] != '\0')
		len++;
	if (checkpoint[fd][len] == '\n')
		len++;
	line = ft_substr(checkpoint[fd], 0, len);
	if (!line)
		return (free(checkpoint[fd]), checkpoint[fd] = NULL, NULL);
	tmp = checkpoint[fd];
	checkpoint[fd] = ft_substr(checkpoint[fd], len,
			(ft_strlen(checkpoint[fd]) - len));
	free(tmp);
	return (line);
}

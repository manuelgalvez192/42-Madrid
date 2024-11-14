/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:43:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/11/14 15:32:32 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *line, char **new_line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i + j])
	{
		(*new_line)[j] = line[i + j];
		line[i + j] = '\0';
		j++;
	}
	(*new_line)[j] = '\0';
	return (line);
}

char	*finalize_line(char *line, char **new_line)
{
	cut_line(line, new_line);
	if (line[0] == '\0')
	{
		if (*new_line)
		{
			free(*new_line);
			*new_line = NULL;
		}
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset_gnl(ptr, 0, total_size);
	return (ptr);
}

char	*free_null(char **buffer, char **new_line)
{
	if (*new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*new_line[1024];
	char		*buffer;
	char		*line;
	int			read_bytes;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!new_line[fd])
		new_line[fd] = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !new_line[fd] || !buffer)
		return (free_null(&buffer, &new_line[fd]));
	line = ft_strjoin_gnl(NULL, new_line[fd]);
	read_bytes = 1;
	while (!ft_strchr_gnl(buffer, '\n') && read_bytes > 0
		&& !ft_strchr_gnl(line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(line), line = NULL, free_null(&buffer, &new_line[fd]));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	return (free(buffer), finalize_line(line, &new_line[fd]));
}

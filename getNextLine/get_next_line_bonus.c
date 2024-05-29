/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:43:34 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/05/27 19:44:00 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

char	*free_null(char **buffer, char **new_line)
{
	if (*new_line)
		free(*new_line);
	*new_line = NULL;
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*new_line[256];
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (!new_line[fd])
		new_line[fd] = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!new_line[fd])
		new_line[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !buffer || !new_line[fd])
		return (free_null(&buffer, &new_line[fd]));
	line = ft_strjoin(NULL, new_line[fd], 0);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer, 1);
	}
	return (free(buffer), finalize_line(line, &new_line[fd]));
}

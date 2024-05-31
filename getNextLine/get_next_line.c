/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:25 by mgalvez-         ###   ########.fr       */
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
	static char	*new_line = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!new_line)
		new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !new_line)
		return (free_null(&buffer, &new_line));
	line = ft_strjoin(NULL, new_line);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0 && !ft_strchr(line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), finalize_line(line, &new_line));
}

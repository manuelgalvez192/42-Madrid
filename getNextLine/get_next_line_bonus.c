/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:32:22 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:25 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_new_line(char *buffer)
{
	int	count;

	count = 0;
	while (buffer[count])
	{
		if (buffer[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

char	*cut_line(char *line, char **buffer, char *new_line)
{
	char	*aux;
	int		i;
	int		j;

	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while ((*buffer)[i] != '\n')
	{
		aux[i] = (*buffer)[i];
		i++;
	}
	line = ft_strjoin(line, aux, 1);
	j = 0;
	while ((*buffer)[i])
	{
		new_line[j] = (*buffer)[i];
		i++;
		j++;
	}
	while (new_line[j])
		new_line[j++] = '\0';
	free(*buffer);
	return (*buffer = NULL, free(aux), line);
}

char	*free_null(char **buffer, char **new_line)
{
	if (*new_line)
		free (*new_line);
	*new_line = NULL;
	if (*buffer)
		free (*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*new_line[256];
	char		*buffer;
	char		*line;
	int			bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_line[fd])
		new_line[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strjoin(new_line[fd], buffer, 0);
	if (fd < 0 || !buffer || !new_line[fd] || BUFFER_SIZE <= 0)
		return (free_null(&buffer, &new_line[fd]));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free (line), free_null(&buffer, &new_line[fd]));
	while (bytes_read > 0)
	{
		if (find_new_line(buffer))
			return (line = cut_line(line, &buffer, new_line[fd]));
		line = ft_strjoin(line, buffer, 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free_null(&buffer, &new_line[fd]);
	return (line);
}

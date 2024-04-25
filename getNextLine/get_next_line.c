/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:17:36 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/25 21:27:18 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		bytes_read;
	size_t		i;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_calloc(1, sizeof(char));
	if (fd < 0 || !buffer || !line || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(line, cut_line(buffer));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				i = ft_strlen(line) - ft_strlen(buffer) + i;
				line[i + 1] = '\0';
				free(buffer);
				return (line);
			}
			i++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	i = ft_strlen(line) - ft_strlen(buffer) + i;
	line[i] = '\0';
	free(buffer);
	return (line);
}

char	*cut_line(char *buffer)
{
	int		i;
	char	*new_line;
	int		j;

	i = 0;
	j = 0;
	new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			while (buffer[i])
			{
				new_line[j] = buffer[i];
				i++;
				j++;
			}
		}
		i++;
	}
	return (new_line);
}

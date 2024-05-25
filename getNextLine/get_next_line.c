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

char	*cut_line(char	*line, char *new_line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		*new_line = line[i];
		line[i] = '\0';
		new_line++;
		i++;
	}
	while (*new_line)
	{
		*new_line = '\0';
		new_line++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*buffer;
	char		*line;
	int			read_bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || !new_line)
		return (NULL);
	line = ft_strjoin(new_line, buffer, 0);
	read_bytes = 1;
	while (!(ft_strchr(buffer, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
			return (free_null(&buffer, &new_line));
		line = ft_strjoin(line, buffer, 1);
	}
	free(buffer);
	line = cut_line(line, new_line);
	if (*new_line == '\0')
	{
		free(new_line);
		new_line = NULL;
	}
	if (*line == '\0' && !new_line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

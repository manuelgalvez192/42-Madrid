/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:17:36 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 20:45:30 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*cut_line(char *line, char **buffer, char **new_line)
{
	int	i;
	int	j;
	int	len_line;

	len_line = ft_strlen(line);
	i = 0;
	while ((*buffer)[i] != '\n')
	{
		line[len_line] = (*buffer)[i];
		len_line++;
		i++;
		if ((*buffer)[i] == '\n')
			line[len_line] = '\0';
	}
	j = 0;
	while ((*buffer)[i])
	{
		(*new_line)[j] = (*buffer)[i];
		i++;
		j++;
	}
	while ((*new_line)[++j])
		(*new_line)[j] = '\0';
	free (*buffer);
	*buffer = NULL;
	//printf ("\nMemory --> %p\n", line);
	return (line);
}

void	free_null(char **buffer, char **new_line)
{
	free (*new_line);
	*new_line = NULL;
	free (*buffer);
	*buffer = NULL;
}

char	*null_ret(char *buffer, char *line, char *new_line)
{
	if (buffer)
		free (buffer);
	if (line)
		free (line);
	if (new_line)
		free (new_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*buffer;
	char		*line;
	size_t		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strjoin(new_line, buffer);
	if (fd < 0 || !buffer || !new_line || BUFFER_SIZE <= 0)
		return (null_ret(buffer, line, new_line));
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (find_new_line(buffer))
		{
			line = cut_line(line, &buffer, &new_line);
			return (line);
		}
		line = ft_strjoin(line, buffer);
	}
	free_null(&buffer, &new_line);
	return (line);
}

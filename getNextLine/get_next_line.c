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
	line = ft_strjoin(line, "\n", 1);
	line = ft_strjoin(line, "\0", 1);
	j = 0;
	while ((*buffer)[i])
	{
		new_line[j++] = (*buffer)[i];
		i++;
	}
	while (new_line[j])
		new_line[j++] = '\0';
	return (free(*buffer), free(aux), line);
}


char	*static_content(char *line, char **new_line)
{
	char	*aux;
	int		i;

	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (**new_line != '\n' && **new_line != '\0')
	{
		aux[i++] = **new_line;
		(*new_line)++;
	}
	aux[i] = '\n';
	free (line);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strjoin(line, aux, 1);
	line = ft_strjoin(line, "\0", 1);
	return (free(aux), line);
}
static void aux_get_next_line(char **buffer, char **new_line, char **line)
{
	
	(*buffer) = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(*new_line))
		(*new_line) = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	(*new_line)++;
	(*line) = ft_strjoin((*new_line), (*buffer), 0);
}
char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*buffer;
	char		*line;
	int			bytes_read;

	bytes_read = 0;
	aux_get_next_line(&buffer, &new_line, &line);
	if (fd < 0 || !buffer || !new_line || BUFFER_SIZE <= 0)
		return (free_null(&buffer, &new_line));
	if (!ft_strchr(new_line, '\n'))
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 && !ft_strchr(new_line, '\n'))
	 	return (NULL);
	while (bytes_read > 0 && (!ft_strchr(new_line, '\n') || !ft_strchr(buffer, '\0')))
	{
		if (ft_strchr(buffer, '\n'))
			return (line = cut_line(line, &buffer, new_line));
		line = ft_strjoin(line, buffer, 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && (ft_strchr(new_line, '\n')))
		return(free(buffer), static_content(line, &new_line));
	if (!ft_strchr(new_line, '\n') && !ft_strchr(buffer, '\0'))
		free_null(&buffer, &new_line);
	return (line);
}



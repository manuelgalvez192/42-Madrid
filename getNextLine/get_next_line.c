/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:17:36 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/08 19:41:17 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *cut_line(char *line)
{
    int i;
    char *new_line;
    int j;

	i = 0;
	j = 0;
	new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while(line[i])
    {
        if(line[i] == '\n')
        {
            i++;
            while(line[i])
            {
                new_line[j] = line[i];
                i++;
                j++;
            }
        }
        i++;
    }
    return (new_line);
}

char	*get_next_line(int fd)
{
    static char	*buffer;
    static char	*backup;
    char	*line;
    size_t	bytes_read;
    size_t	i;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    line = ft_calloc(1, sizeof(char));
	if (!backup)
		backup = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

    if (fd < 0 || !buffer || !line)
        return (NULL);
	free(line);
    line = ft_strjoin(line, backup);
	free(backup);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        line = ft_strjoin(line, buffer);
        i = 0;
        while(i < bytes_read)
        {
            if (buffer[i] == '\n')
            {
                i = ft_strlen(line) - ft_strlen(buffer) + i;
                line[i + 1] = '\0';
				backup = cut_line(buffer);
                return (line);
            }
            if (buffer[i] == '\0')
            {
				i = ft_strlen(line) - ft_strlen(buffer) + i;
                line[i + 1] = '\0';
                free(buffer);
				free(backup);
                return (line);
            }
            i++;
        }
    }
    return (line);
}

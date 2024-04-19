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

char	*get_next_line(int fd)
{
    static char    *buffer;
    char    *line;
    size_t  bytes_read;
    ssize_t i;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    line = ft_calloc(1, sizeof(char));

    if (fd < 0 || !buffer || !line)
        return (NULL);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        line = ft_strjoin(line, buffer);
        i = 0;
        while(i < bytes_read)
        {
            if (buffer[i] == '\n')
            {
                line[i] = '\0';
                return (line);
            }
            if (buffer[i] == '\0')
            {
                free(buffer);
                return (line);
            }
            i++;
        }
    }
    return (line);
}

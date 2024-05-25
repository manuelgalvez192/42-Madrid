
#include "get_next_line_bonus.h"

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

char	*finalize_line(char *line, char **new_line)
{
	line = cut_line(line, *new_line);
	if (**new_line == '\0')
	{
		free(*new_line);
		*new_line = NULL;
	}
	if (*line == '\0' && !*new_line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*new_line[256];
	char		*buffer;
	char		*line;
	int			read_bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_line[fd])
		new_line[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || !new_line[fd])
		return(free_null(&buffer, &new_line[fd]));
	line = ft_strjoin(new_line[fd], buffer, 0);
	read_bytes = 1;
	while (!(ft_strchr(buffer, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
			return (free_null(&buffer, &new_line[fd]));
		line = ft_strjoin(line, buffer, 1);
	}
	free(buffer);
	return (finalize_line(line, &new_line[fd]));
}

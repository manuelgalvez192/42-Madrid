/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:23:09 by mgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 20:37:46 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main() {
	int fd = open("file.txt", O_RDONLY);

	char *line;
	do
	{
		line = get_next_line(fd);
		if (line == NULL)
			printf("FIN\n");
		else
			printf("%s", line);
		free (line);
	}while (line != NULL);
	close(fd);
	system ("leaks a.out");
	return 0;
}

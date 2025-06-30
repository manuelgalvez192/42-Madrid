/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:12:31 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/30 15:30:31 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	cleanup(t_data *data)
{
    int i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->end_simulation_mutex);
	i = 0;
    while (i < data->num_of_philo)
	{
        pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	free(data->philos);
	free(data->forks);
	free(data);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

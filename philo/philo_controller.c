/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:41:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/01 00:41:04 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_philo *philo, const char *message)
{
	long	timestamp;
	t_data	*data = philo->data;

	pthread_mutex_lock(&data->print_mutex);
	if (!data->end_simulation)
	{
		timestamp = get_time() - data->start_simulation;
		printf("%ld %d %s\n", timestamp, philo->id, message);
	}
	pthread_mutex_unlock(&data->print_mutex);
}

long get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}


bool	is_simulation_over(t_data *data)
{
	bool result;

	pthread_mutex_lock(&data->end_simulation_mutex);
	result = data->end_simulation;
	pthread_mutex_unlock(&data->end_simulation_mutex);
	return (result);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->num_of_philo)
		{
			if ((get_time() - data->philos[i].last_meal_time) > data->time_to_die)
			{
				print_status(&data->philos[i], "died");
				pthread_mutex_lock(&data->end_simulation_mutex);
				data->end_simulation = true;
				pthread_mutex_unlock(&data->end_simulation_mutex);
				data->philos[i].alive = false;
				return (NULL);
			}
		}
	}
	return (NULL);
}

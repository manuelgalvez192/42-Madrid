/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:41:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 17:36:43 by mgalvez-         ###   ########.fr       */
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
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(long sleep_time)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < sleep_time)
	{
		usleep(100);
	}
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
	t_data	*data = (t_data *)arg;
	int		i;

	while (1)
	{
		if (all_philos_full(data))
            return (NULL);
		i = -1;
		while (++i < data->num_of_philo)
		{
			// Si este filósofo ya está marcado como 'full', lo salto.
			pthread_mutex_lock(&data->philos[i].meal_mutex);
			bool is_full = data->philos[i].full;
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			if (is_full)
				continue;

			// Ahora sí: si ha pasado demasiado tiempo desde su última comida, muere.
			pthread_mutex_lock(&data->philos[i].meal_mutex);
			long	time_since_last = get_time() - data->philos[i].last_meal_time;
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			if (time_since_last > data->time_to_die)
			{
				pthread_mutex_lock(&data->end_simulation_mutex);
				print_status(&data->philos[i], "died");
				data->end_simulation = true;
				pthread_mutex_unlock(&data->end_simulation_mutex);

				pthread_mutex_lock(&data->philos[i].meal_mutex);
				data->philos[i].alive = false;
				pthread_mutex_unlock(&data->philos[i].meal_mutex);
				return (NULL);
			}
		}
		usleep(100);
	}
	return (NULL);
}


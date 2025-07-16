/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:41:04 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/16 17:42:52 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_philo *philo, const char *message)
{
	long	timestamp;
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	if (!is_simulation_over(data))
	{
		timestamp = ft_get_time() - data->start_simulation;
		printf("%ld %d %s\n", timestamp, philo->id, message);
	}
	pthread_mutex_unlock(&data->print_mutex);
}

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(long sleep_time)
{
	long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < sleep_time)
	{
		usleep(100);
	}
}

bool	die_check(t_data *data, int i, long time_since_last)
{
	pthread_mutex_lock(&data->philos[i].meal_mutex);
	if (time_since_last > data->time_to_die)
	{
		data->philos[i].alive = false;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		print_status(&data->philos[i], "\001\033[31m\002died\001\033[0m\002");
		pthread_mutex_lock(&data->end_simulation_mutex);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->end_simulation_mutex);
		return (false);
	}
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	return (true);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		if (all_philos_full(data))
			return (NULL);
		i = -1;
		while (++i < data->num_of_philo)
			if (is_philo_dead_or_full(data, i))
				return (NULL);
		usleep(100);
	}
	return (NULL);
}

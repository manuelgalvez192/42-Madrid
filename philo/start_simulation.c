/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:52:12 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/07/16 17:54:22 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	all_philos_full(t_data *data)
{
	bool	is_full;
	int		i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		is_full = data->philos[i].full;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (!is_full)
			return (false);
		i++;
	}
	return (true);
}

bool	is_simulation_over(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data->end_simulation_mutex);
	result = data->end_simulation;
	pthread_mutex_unlock(&data->end_simulation_mutex);
	return (result);
}

void	*simulation(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	bool	got_forks;

	philo = arg;
	data = philo->data;
	if (data->num_of_philo == 1)
		return (one_philo_case(philo, data));
	while (!is_simulation_over(data) && !philo->full)
	{
		think(philo);
		got_forks = take_forks(philo);
		if (got_forks)
		{
			if (!is_simulation_over(data))
				eat(philo);
			release_forks(philo);
		}
		if (philo->full || is_simulation_over(data))
			break ;
		sleep_philo(philo);
	}
	return (NULL);
}

void	*one_philo_case(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->first_fork->mutex);
	print_status(philo, "has taken a fork");
	smart_sleep(data->time_to_die);
	pthread_mutex_unlock(&philo->first_fork->mutex);
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	if (data->must_eat == 0)
		return ;
	data->start_simulation = ft_get_time();
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		data->philos[i].last_meal_time = data->start_simulation;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor, data);
	usleep(1000);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_create(&data->philos[i].thread_id, NULL, &simulation,
			&data->philos[i]);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_join(data->philos[i].thread_id, NULL);
	pthread_join(monitor_thread, NULL);
}

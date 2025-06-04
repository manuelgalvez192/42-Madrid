/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez- <mgalvez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:52:12 by mgalvez-          #+#    #+#             */
/*   Updated: 2025/06/04 16:46:23 by mgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	all_philos_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (!data->philos[i].full)
			return (false);
		i++;
	}
	return (true);
}

void	*simulation(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (!philo->data->end_simulation)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		sleep_philo(philo);
	}
	return (NULL);
}


void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	if (data->must_eat == 0)
		return ;
	else if (data->num_of_philo == 1)
	{
		data->start_simulation = get_time();
		data->philos[0].last_meal_time = data->start_simulation;
		pthread_create(&monitor_thread, NULL, &monitor, data);
		pthread_create(&data->philos[0].thread_id, NULL, &simulation, &data->philos[0]);
		pthread_join(data->philos[0].thread_id, NULL);
		pthread_join(monitor_thread, NULL);
	}
	else
	{
		data->start_simulation = get_time(); 
		i = -1;
		while (++i < data->num_of_philo)
			data->philos[i].last_meal_time = data->start_simulation;
		pthread_create(&monitor_thread, NULL, &monitor, data);
		i = -1;
		while (++i < data->num_of_philo)
			pthread_create(&data->philos[i].thread_id, NULL, &simulation, &data->philos[i]);
		i = -1;
		while (++i < data->num_of_philo)
			pthread_join(data->philos[i].thread_id, NULL);
		pthread_join(monitor_thread, NULL);
	}
}
